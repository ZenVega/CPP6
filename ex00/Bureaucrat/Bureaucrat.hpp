/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:49:49 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/02 11:26:15 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "../includes/CONSTANTS.hpp"
#include <bits/stdc++.h>
#include <exception>

class Bureaucrat
{
private:
	const string _name;
	int			 _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(string name, int grade);
	~Bureaucrat();

	int			getGrade(void) const;
	void		setGrade(int grade);
	string		getName(void) const;
	Bureaucrat &operator=(const Bureaucrat &other);

	void increment(void);
	void decrement(void);
	class GradeTooHighException : public std::exception
	{
	public:
		// Override what() function
		const char *what() const throw(); // c+++98 synthx deprecated in c++11;
		// const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
;

ostream &operator<<(ostream &out, const Bureaucrat &other);

#endif
