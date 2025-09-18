/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:04:23 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 14:47:16 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include <iostream>

using std::cout;
using std::endl;

B::B()
{
	cout << "Secret Base created" << endl;
}

B::~B()
{
	cout << "Secret Base(B) destroyed" << endl;
}
