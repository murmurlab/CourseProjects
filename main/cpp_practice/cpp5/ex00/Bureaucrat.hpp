/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbasara <ahbasara@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:08 by ahbasara          #+#    #+#             */
/*   Updated: 2024/09/01 01:30:00 by ahbasara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>

# include "common.hpp"

using std::exception;
using std::cout;
using std::ostream;
using std::cerr;
using std::endl;
using std::string;


class Bureaucrat
{
	private:
		const string	_name;
		int				_grade;
		class GradeTooHighException;
		class GradeTooLowException;
		Bureaucrat();
	public:
		void			gradeUp(int grade);
		void			gradeDown(int grade);
		const string&	getName( void );
		int				getGrade( void );
		Bureaucrat(string name, int grade);
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat &operator=(Bureaucrat &assignment);
		~Bureaucrat();
};

# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

ostream& operator<<(ostream& os, Bureaucrat& bro);

#endif
