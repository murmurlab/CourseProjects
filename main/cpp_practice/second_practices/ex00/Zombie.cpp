# include "./Zombie.hpp"

void Zombie::announce( void ){
cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::Zombie(string be_name){
name = be_name;
}

Zombie::~Zombie(){
cout << "zombie " << name << " is perished" << endl;
}
