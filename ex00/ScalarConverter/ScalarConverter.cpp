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

// atoi(str.c_str());
// atof(str.c_str());

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

static void printResult(InputType type, string input)
{
	cout << "int: "
		 << atoi(input.c_str()) << endl;
	cout << "char: "
		 << "impossible" << endl;
	cout << "float: ";
	if (stoi(input) < 128 && stoi(input) > 31)
		cout << (char)stoi(input);
	else
		cout << "Non displayable";
	cout << endl;
	cout << "double: "
		 << stod(input) << endl;
}

static InputType getInitialType(string input)
{
	int length = input.length();
	if (length == 0)
		return UNDEFINED;
	if (length == 1)
		return CHAR;
	if (input.find("inf"))
		return (input[0] == '-' ? INF_NEG : INF);
	return STRING;
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

	InputType init_type = getInitialType(input);
	if (init_type == UNDEFINED)
		printResult(UNDEFINED);
	else if (init_type == INF || init_type == INF_NEG)
		printResult(init_type);
	else
		printResult(STRING, input);
};
