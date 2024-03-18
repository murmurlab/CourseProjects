# include "./Zombie.hpp"

// https://stackoverflow.com/a/67967472/13259301
Zombie* zombieHorde( int N, string name ){
Zombie* zombies = new Zombie[N];
for (size_t i = 0; i < N; i++){
    zombies[i].setName(name);
    zombies[i].announce();
}
return zombies;
}