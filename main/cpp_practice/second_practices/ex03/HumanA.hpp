/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/18 10:27:04 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_H
# define HUMANA_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# include <iostream>
# include "./Weapon.hpp"

# define RED				"\x1B[31m"
# define GREEN				"\x1B[32m"
# define YELLOW				"\x1B[33m"
# define BLUE				"\x1B[34m"
# define RESET				"\x1B[0m"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class HumanA
{
private:
    Weapon weapon;
    string name;
public:
    HumanA(string given_name, Weapon &given_weapon);
    // ~HumanA();
    void attack();
};

#endif
