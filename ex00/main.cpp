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

#include "ScalarConverter/ScalarConverter.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "Invalid Input" << endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
