/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:04:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 14:47:08 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include <iostream>

using std::cout;
using std::endl;

A::A()
{
	cout << "Secret Base created" << endl;
}

A::~A()
{
	cout << "Secret Base(A) destroyed" << endl;
}
