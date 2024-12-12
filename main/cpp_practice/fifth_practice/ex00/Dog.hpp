#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
    Dog( void );
    ~Dog( void );

    void   makeSound( void ) const;
};

#endif // DOG_HPP