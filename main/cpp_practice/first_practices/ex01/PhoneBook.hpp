/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/03/15 13:50:16 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# if defined(__linux__)
/* Linux. --------------------------------------------------- */

# elif defined(__APPLE__)
/* OSX. --------------------------------------------------- */

# endif

# include "./Contact.hpp"   
class PhoneBook{
int printVertical(Contact &contact, size_t idx);
int printHorizontal(Contact &contact, int swicth);
int older;
Contact contacts[MAX_CONTACTS];
public:
PhoneBook();
int add();
int search();
int exit();};

#endif
