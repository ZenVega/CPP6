/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:28:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/02 11:43:22 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :
	_name("unknown"),
	_grade(150)
{
	cout << "An unknown Burocreat is appointed" << endl;
}

Bureaucrat::Bureaucrat(string name, int grade) :
	_name(name)
{
	this->setGrade(grade);
	cout << "An Burocreat of the name " << _name << " is appointed" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other.getName()),
	_grade(other.getGrade())
{
	cout << "An Burocreat of the name " << _name << " is appointed" << endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->setGrade(other.getGrade());
	}
	std::cout << "Copy Assignment Operator Called!" << std::endl;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	cout << "The Burocreat of name: " << _name << " and grade " << _grade << " retires" << endl;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	_grade = grade;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

string Bureaucrat::getName(void) const
{
	return _name;
}

void Bureaucrat::increment(void)
{
	if (_grade - 1 < 1)
		throw GradeTooLowException();
	_grade--;
	cout << _name << " raised to lv: " << _grade << endl;
}

void Bureaucrat::decrement(void)
{
	if (_grade + 1 > 150)
		throw GradeTooHighException();
	_grade++;
	cout << _name << " lowered to lv: " << _grade << endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "This grade is beyond the Burocreats boundaries";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "A Burocreats may never have that low a grade";
}

ostream &operator<<(ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return out;
}
