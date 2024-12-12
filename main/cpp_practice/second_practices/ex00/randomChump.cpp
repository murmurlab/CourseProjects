# include "./Zombie.hpp"

void randomChump( std::string name ){
Zombie *zom = newZombie(name);
zom->announce();
delete zom;
}