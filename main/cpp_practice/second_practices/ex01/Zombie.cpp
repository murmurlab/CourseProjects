# include "./Zombie.hpp"

void Zombie::announce( void ){
cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

void Zombie::setName(string given_name){
    name = given_name;
}

Zombie::Zombie(){
}

Zombie::~Zombie(){
cout << "zombie " << name << " is perished" << endl;
}
