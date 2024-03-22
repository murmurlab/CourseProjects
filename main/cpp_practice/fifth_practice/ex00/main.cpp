#include "ClapTrap.hpp"

int main(int argc, char const *argv[]){
ClapTrap    one("one");
ClapTrap    two("two");
ClapTrap    three("three");

one.attack("two");
cout << endl;
cout << endl;
two.takeDamage(6);
two.beRepaired(6);
two.beRepaired(6);
two.takeDamage(6);
two.takeDamage(6);
two.takeDamage(6);
two.takeDamage(6);
cout << endl;
cout << endl;
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
one.beRepaired(0);
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
