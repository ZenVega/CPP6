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
#include <cfloat>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <stdlib.h>

#define PREC_FLOAT 6
#define PREC_DOUB 15

using std::cout;
using std::endl;
using std::string;

static bool allDigits(char *string)
{
	bool decimal  = false;
	bool sym_e	  = false;
	bool sym_plus = false;
	bool sym_f	  = false;
	if (string[0] == '-' || string[0] == '+')
		string++;
	for (int i = 0; string[i]; i++)
		if ((string[i] < 48 || string[i] > 57))
		{
			if (string[i] == '.' && !decimal && string[i + 1])
				decimal = true;
			else if ((string[i] == 'e' || string[i] == 'E') && !sym_e && string[i + 1])
				sym_e = true;
			else if ((string[i] == '+' || string[i] == '-') && !sym_plus && string[i + 1])
				sym_plus = true;
			else if (string[i] == 'f' && !sym_f && !string[i + 1])
				sym_f = true;
			else
				return false;
		}
	return true;
}
static bool checkIntOverflow(double check_val)
{
	if (check_val > INT_MAX || check_val < INT_MIN)
		return true;
	return false;
}

static bool checkFloatOverflow(double check_val)
{
	double abs_val = (check_val < 0) ? -check_val : check_val;
	if (abs_val > FLT_MAX)
		return true;
	if (check_val != 0.0 && abs_val < FLT_MIN)
		return true;
	return false;
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

static void printSpecial(char *input)
{
	string str = input;
	cout
		<< "char: impossible" << endl;
	cout << "int: impossible" << endl;
	if (str[str.size() - 1] == 'f')
	{
		cout << "float: " << str << endl;
		cout << "double: " << str.substr(0, str.size() - 1) << endl;
	}
	else
	{
		cout << "float: " << str << "f" << endl;
		cout << "double: " << str << endl;
	}
	return;
}

static void printChar(t_literal_rep &literals, char *input)
{
	literals.c = input[0];
	literals.i = static_cast<int>(input[0]);
	literals.f = static_cast<float>(input[0]);
	literals.d = static_cast<double>(input[0]);
	cout << "int: "
		 << literals.i << endl;
	cout << "char: "
		 << literals.c << endl;
	cout << "float: ";
	cout << format_double(literals.f, PREC_FLOAT) << "f" << endl;
	cout << "double: ";
	cout << format_double(literals.d, PREC_DOUB) << endl;
}

static void printResult(char *input)
{
	char	 *endptr = NULL;
	double val_d  = std::strtod(input, &endptr);
	// stdtod stops saves last read digit at endptr

	if (!allDigits(input))
	{
		cout << "Invalid Input" << endl;
		return;
	}
	if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0'))
	{
		cout << "Double overflow:" << endl;
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: nanf" << endl;
		cout << "double: nan" << endl;
		return;
	}

	if (val_d < 0 || val_d > 127)
		cout << "char: impossible" << endl;
	else if (!isprint(static_cast<int>(val_d)))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: " << static_cast<char>(val_d) << endl;

	if (checkIntOverflow(val_d))
	{
		cout << "Int overflow:" << endl;
		cout << "int: impossible" << endl;
	}
	else
		cout << "int: " << static_cast<int>(val_d) << endl;

	if (checkFloatOverflow(val_d))
	{
		cout << "Float overflow" << endl;
		cout << "float: impossible" << endl;
	}
	else
	{
		cout << "float: ";
		cout << format_double(val_d, PREC_FLOAT) << "f" << endl;
	}

	cout << "double: " << format_double(val_d, PREC_DOUB) << endl;
}

static InputType getInitialType(char *input)
{
	string input_str = input;
	int	   length	 = input_str.length();
	if (input_str.find("inf") != string::npos)
		return (SPECIAL);
	if (length == 0 || input_str.find("nan") != string::npos)
		return SPECIAL;
	if (length == 1 && input[0] >= ' ' && input[0] <= 126)
	{
		if (input[0] >= '0' && input[0] <= '9')
			return INT;
		else
			return CHAR;
	}
	else
		return INT;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(char *input)
{
	t_literal_rep literals;

	InputType init_type = getInitialType(input);
	if (init_type == SPECIAL)
		printSpecial(input);
	else if (init_type == CHAR)
		printChar(literals, input);
	else
		printResult(input);
};
