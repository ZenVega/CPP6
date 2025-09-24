/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:49:47 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/08 11:04:13 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

enum InputType
{
	CHAR,
	SPECIAL,
	INF,
	INT
};

typedef struct s_literal_rep
{
	char   c;
	int	   i;
	float  f;
	double d;
} t_literal_rep;

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);

public:
	static void convert(char *input);
};
#endif
