#define EMPTY_INPUT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

#include <iostream>
using std::cout;
using std::endl;

int	main(int argc, char const *argv[]){
size_t	_ = 1;

if (argc < 2){
	cout
		<< EMPTY_INPUT << endl;
	return 1;}
while (argv[_]){
	std::string tmp(argv[_++]);
	for (size_t i = 0; tmp[i]; i++) tmp[i] = std::toupper(tmp[i]);
	cout
		<< tmp;
	}
cout
	<< endl;
return 0;}