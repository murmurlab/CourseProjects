/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/15 13:17:59 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_H
# define CONTACT_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# include "./depend.hpp"

class Contact{
public:
string  get_first_name();
string  get_last_name();
string  get_nick_name();
string  get_phone_num();
string  get_secret();

int     set_first_name(string in);
int     set_last_name(string in);
int     set_nick_name(string in);
int     set_phone_num(string in);
int     set_secret(string in);

private:
string  first_name;
string  last_name;
string  nick_name;
string  phone_num;
string  secret;
};

#endif
