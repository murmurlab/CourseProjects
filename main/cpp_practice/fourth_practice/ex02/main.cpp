#include "FragTrap.hpp"

int main(int argc, char const *argv[]){
FragTrap    one("one");
FragTrap    two("two");
FragTrap    three("three");

one.attack("two");
cout << endl;
cout << endl;
two.takeDamage(6);
two.beRepaired(6);
two.beRepaired(6);
two.takeDamage(6);
two.takeDamage(60);
two.takeDamage(60);
two.takeDamage(60);
cout << endl;
cout << endl;

for (size_t i = 0; i < 99; i++){
one.beRepaired(0);
}
one.attack("noneeeeee");
cout << endl;
cout << endl;
one.takeDamage(155);
cout << endl;
cout << endl;
three = one; // both name one
three.attack("when dead"); //name one
one.attack("when dead"); //name one
return 0;
}
