#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:

public:
    Cat( void );
    ~Cat( void );

    void   makeSound( void ) const;
};

#endif // CAT_HPP