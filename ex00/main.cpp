/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:26:15 by uschmidt          #+#    #+#             */
/*   Updated: 2025/08/28 15:26:15 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.hpp"
#include <exception>

int main()
{
	Bureaucrat no_name;
	Bureaucrat b1 = Bureaucrat("Wilhelm", 12);
	Bureaucrat b2 = Bureaucrat("Toni", 150);
	try
	{
		Bureaucrat b3 = Bureaucrat("Henriette", 0);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		cout << "Exception type LOW caught: " << e.what() << endl;
	}
	cout << b1 << endl;
	cout << b2 << endl;

	try
	{
		b1.increment();
		b2.decrement();
	}
	catch (const std::exception &e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}
	cout << b1 << endl;
	cout << b2 << endl;
	return 0;
}
