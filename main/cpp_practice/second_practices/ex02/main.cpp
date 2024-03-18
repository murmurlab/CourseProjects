# include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
string  variable = "HI THIS IS BRAIN";
string  *stringPTR = &variable;
string  &stringREF = variable;

cout<< &variable <<endl;
cout<< stringPTR <<endl;
cout<< &stringREF <<endl;

cout<< variable <<endl;
cout<< *stringPTR <<endl;
cout<< stringREF <<endl;
return 0;
}
