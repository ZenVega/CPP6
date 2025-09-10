/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:50:06 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/08 11:10:36 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void printResult(InputType type, void *_)
{
	cout << "int: " << "impossible" << endl;
	cout << "char: " << "impossible" << endl;
	if (type == UNDEFINED)
	{
		cout << "float: "
			 << "nanf" << endl;
		cout << "double: "
			 << "nan" << endl;
	}
	else
	{
		string f = (type == INF) ? "+inff" : "-inff";
		string d = (type == INF) ? "+inf" : "-inf";
		cout << "float: " << f << endl;
		cout << "double: " << d << endl;
	}

	static void printResult(InputType type, t_literal_rep & literals)
	{
		if (type == UNDEFINED)
		{
			cout << "int: "
				 << "impossible" << endl;
			cout << "char: "
				 << "impossible" << endl;
			cout << "float: "
				 << "nanf" << endl;
			cout << "double: "
				 << "nan" << endl;
		}
		cout << "int: " << literals.i << endl;
		cout << "char: " << literals.c << endl;
		cout << "float: " << literals.f << endl;
		cout << "double: " << literals.d << endl;
	}

	static InputType getInitialType(string input, t_literal_rep & literals)
	{
		int length = input.length();
		if (length == 0)
			return UNDEFINED;
		if (length == 1)
		{
			literals.c = input[0];
			return CHAR;
		}
		return UNDEFINED;
	}

	ScalarConverter::ScalarConverter(void){};
	ScalarConverter::ScalarConverter(const ScalarConverter &other){};
	ScalarConverter::~ScalarConverter(void){};
	ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
	{
		return *this;
	};

	void ScalarConverter::convert(string input)
	{
		t_literal_rep literals;

		InputType init_type = getInitialType(input, literals);
		if (init_type == UNDEFINED)
			printResult(UNDEFINED, NULL);
	};
