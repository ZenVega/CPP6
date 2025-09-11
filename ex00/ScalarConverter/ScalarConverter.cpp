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

static void fill_literals(char *input, t_literal_rep &literals, InputType type)
{
	if (type == CHAR)
	{
		literals.c = input[0];
		literals.i = static_cast<int>(input[0]);
		literals.f = static_cast<float>(input[0]);
		literals.d = static_cast<double>(input[0]);
	}
	else
	{
		literals.d = atof(input);
		literals.f = (float)literals.d;
		literals.i = atoi(input);
		if (literals.i > 31 && literals.i < 128)
			literals.c = (char)literals.i;
		else
			literals.c = 0;
	}
};

static void printResult(InputType type)
{
	cout << "int: "
		 << "impossible" << endl;
	cout << "char: "
		 << "impossible" << endl;
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
}

static void printResult(t_literal_rep &literals)
{
	cout << "int: "
		 << literals.i << endl;
	cout << "char: ";
	if (literals.c)
		cout << literals.c << endl;
	else
		cout << "impossible" << endl;
	cout.precision(1);
	cout << std::fixed << "float: " << literals.f << "f" << endl;
	cout.precision(1);
	cout << std::fixed << "double: " << literals.d << endl;
}

static InputType getInitialType(char *input)
{
	string input_str = input;
	int	   length	 = input_str.length();
	if (length == 0)
		return UNDEFINED;
	if (length == 1)
		return CHAR;
	// find returns npos if not found
	if (input_str.find("inf") != string::npos)
		return (input[0] == '-' ? INF_NEG : INF);
	return STRING;
}

ScalarConverter::ScalarConverter(void){};
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	if (&other != this)
		return;
};
ScalarConverter::~ScalarConverter(void){};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (&other != this)
		return *this;
	return *this;
};

void ScalarConverter::convert(char *input)
{
	t_literal_rep literals;

	InputType init_type = getInitialType(input);
	if (init_type == UNDEFINED)
		printResult(UNDEFINED);
	else if (init_type == INF || init_type == INF_NEG)
		printResult(init_type);
	else
	{
		fill_literals(input, literals, init_type);
		printResult(literals);
	}
};
