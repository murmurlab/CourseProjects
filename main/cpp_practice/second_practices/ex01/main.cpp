# include "./Zombie.hpp"


int main(int argc, char const *argv[]){
Zombie *zombiez = zombieHorde(3, "an_unnamed_hungry_zombie");
delete[] zombiez;
return 0;
}
