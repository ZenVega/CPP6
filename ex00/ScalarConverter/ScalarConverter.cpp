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
#include <iostream>
#include <sstream>
#include <stdlib.h>

#define PREC_FLOAT 6
#define PREC_DOUB 15

using std::cout;
using std::endl;
using std::string;

static bool allDigits(char *string)
{
	bool decimal = false;
	if (string[0] == '-' || string[0] == '+')
		string++;
	for (int i = 0; string[i]; i++)
		if ((string[i] <= 48 || string[i] >= 57))
		{
			if (string[i] == '.' && !decimal)
				decimal = true;
			else
				return false;
		}
	return true;
}

static string format_double(double val, int precision)
{
	std::stringstream ss;
	ss.precision(precision);
	ss << val;
	string result = ss.str();
	if (result.find(".") == string::npos)
		result.append(".0");
	return result;
};

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

static void printUndefined(void)
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

static void printResult(t_literal_rep &literals, InputType type)
{
	if (type == INF)
	{
		cout << "int: "
			 << "impossible" << endl;
		cout << "char: "
			 << "impossible" << endl;
		cout << std::fixed << "float: " << literals.f << "f" << endl;
		cout << std::fixed << "double: " << literals.d << endl;
		return;
	}
	cout << "int: "
		 << literals.i << endl;
	cout << "char: ";
	if (literals.i > 31 && literals.i < 128)
		cout << literals.c << endl;
	else if (literals.i <= 31)
		cout << "not displayable" << endl;
	else
		cout << "impossible" << endl;
	cout << std::fixed << "float: " << format_double(literals.f, PREC_FLOAT) << "f" << endl;
	cout << std::fixed << "double: " << format_double(literals.d, PREC_DOUB) << endl;
}

static InputType getInitialType(char *input)
{
	string input_str = input;
	int	   length	 = input_str.length();
	if (input_str.find("inf") != string::npos)
		return (INF);
	if (length == 0 || input_str.find("nan") != string::npos)
		return UNDEFINED;
	if (length == 1 && input[0] >= ' ' && input[0] <= 126)
	{
		if (input[0] >= '0' && input[0] <= '9')
			return INT;
		else
			return CHAR;
	}
	if (allDigits(input))
		return INT;
	else
		return UNDEFINED;
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
		printUndefined();
	else
	{
		fill_literals(input, literals, init_type);
		printResult(literals, init_type);
	}
};
