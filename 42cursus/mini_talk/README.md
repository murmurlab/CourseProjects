Minitalk bizden ne istiyor? 
-İki adet programımız olacak, biri server.c diğeri client.c
-client'den gönderdiğimiz mesajı PID ve UNIX sinyallerini kullanarak server'da yazdıracağız.

Kavramlar ve Operatörler
-----------------
PID = Process identification anlamına gelmektedir. Çoğu işletim sisteminde çalışan her programa bir PID atanır. UNIX tabanlı işletim sistemlerinde de bu böyledir. Programımızın benzersiz kimliğidir. C dilinde getpid() fonksiyonunu kullanarak pid'imizi elde edebilir, ekrana yazdırabiliriz.

SIGUSR1 ve SIGUSR2 = her ikisi de birer sinyaldir, define olarak SIGUSR1 = 30, SIGUSR2 = 31'dir. Kullanıcı bu sinyalleri özelleştirebilsin diye vardır. Örneğin biz burada SIGUSR1'i "0", SIGUSR2'yi "1" olarak kullanacağız ve bitlerle haberleşmeyi sağlayacağız.

Fonksiyonlar:
-----------------
-kill(int pid, signal) = parametre olarak gönderilen pid'ye yine parametre olarak gönderilen signali işler.

-getpid() = çalışan programın pid'sini return eder.

-signal(signal, sig_handler()) = signal fonksiyonu iki parametre alır. İlk parametre dışardam aldığı sinyal ikinci parametre ise aldığı sinyali tutacak olan kendi yazdığımız fonksiyondur.

-usleep() -> sinyalleri gönderince delay vermek için kullanıyoruz. Yoksa sinyaller karışabiliyor. Sebebi 1 ve 0'ların bilgisayar tarafından anlaşılma yöntemi OLABİLİR. bilgisayar 5 voltu'u 1, 0 volt'u 0 olarak anlıyor Ancak tam olarak anlaşılabilmesi için işlemcinin belli bir süre 5 volt akımı geçirmiş olması gerekiyor. 

pause() -> bir sinyal alana kadar kodu bekletmeye yarar.

***************

CLIENT İÇİN ALGORİTMA:
-----------------------------------
- parametre olarak aldığı pid'yi kullanabilmek için atoi ile integer'a çevirecek
- tüm stringin her bir karakterlerinin 8 byte'ının 1 olanlarını sıgusr2 olarak, 0 olanlarını sıgusr1 olarak kill ile server'a gönderecek.
- byte'leri byte kaydırma operatörleriyle elde edebiliriz örneğin:
     10010011'de en baştaki byte'ı göndermek istiyorsak aşağıdaki gibi bir           işlem yapabiliriz: 
bit = (byte >> 7) & 1 -> en baştaki byte'ı en sona getirecek, en sondaki byte ile 1'i karşılaştıracak. 1'se eğer bit değerine 1, değilse 0 atanacak.

-eğer bit 1 ise kill ile sigusr2, 0 ise sigusr1 sinyali göndereceğim her bir karakterin her bir byte'ı için


SERVER İÇİN ALGORİTMA:
------------------------------------
Gönderilen sinyalleri signal fonksiyonu ile tutup bir diziye atasın, gelen sinyal 1 ise char *dizi'ye  1, 0 ise 0 yazsın. Sonra taban aritmatiği ile aldığı bitleri karakter'e çevirsin. 

Taban aritmatiği nasıl olacak ?

1---------0--------1---------1----------0--------1---------0----------0

2^7------2^6------2^5-------2^4--------2^3------2^2-------2^1--------2^0

bitin altındaki sayı * bit + diğer bitler yani soldan sağa için:
128 + 0 + 32 + 16 + 0 + 4 + 0 + 0 = 176

Yani yukardaki bitler 176'yı veriyormuş, her ondalık sayının karakter karşılığı olduğundan int to char yaparak karşılığını bulabiliriz.

Oluşturduğumuz char dizisinin ilk elemanından başlayarak eğer soldan ilk bit 1 ise + 128 yapar, 128'i ikiye böler bir sonraki bite aynı işlemi yaparız ta ki bit 0 olana kadar.
