#!/bin/bash

backup=""
insert_file=""
delete_start=false
dosyalar=()

while [ "$#" -gt 0 ]; do
  case "$1" in
    -b)
      backup=".bak"
      ;;
    -in)
      shift
      insert_file="$1"
      ;;
    -ex)
      delete_start=true
      ;;
    *)
      dosyalar+=("$1")
      ;;
  esac
  shift
done

insert_content=""

if [ -n "$insert_file" ]; then
  insert_content="$(cat "$insert_file")\n"
fi

if [ ${#dosyalar[@]} -eq 0 ] || ([ "$delete_start" = false ] && [ -z "$insert_content" ]) ; then
  echo "Kullanım: $0 <<-in path/of/header> | <-ex [-b]>> <file1> [file2 ...]"
  echo "-b                : backup source file"
  echo "-in path/of/header: insert header if doesn't exist"
  echo "-ex               : extract header if it is exist"
  exit 1
fi

for dosya in "${dosyalar[@]}"; do
  satir_sayisi=$(cat "$dosya" | wc -l)

  if [ -f "$dosya" ]; then
    if [ "$delete_start" = true ]; then
      if [[ $satir_sayisi -ge 11 && $(head -n 11 "$dosya" | grep -c '^/\*') -eq 11 ]]; then
        sed -i "$backup" '1,11d' "$dosya"
        echo "delete bulk: $dosya"
      else
        echo "Cant extract! İlk 11 satır /* ile başlamaz: $dosya"
      fi
    fi
    if [ -n "$insert_content" ]; then
      if [[ $satir_sayisi -ge 11 && $(head -n 11 "$dosya" | grep -c '^/\*') -eq 11 ]]; then
        echo "Zaten var! İlk 11 satır /* ile başlar: $dosya"
      else
        echo "$insert_content" > temp_file && cat "$dosya" >> temp_file && mv temp_file "$dosya"
        echo "insert content: $dosya"
      fi
    fi
  else
    echo "Dosya bulunamadı: $dosya"
  fi
done
