/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:26:15 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 11:38:13 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data/Data.hpp"
#include "Serializer/Serializer.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	Data *centipede = new Data("centipede", 1000, 0);
	Data *mantis	= new Data("mantis", 6, 1);
	cout << "Centipede addr. is: " << centipede << endl;
	cout << "Mantis addr. is: " << mantis << endl;
	uintptr_t raw_centi	   = Serializer::serialize(centipede);
	uintptr_t raw_mantis   = Serializer::serialize(mantis);
	Data	 *centi_clone  = Serializer::deserialize(raw_centi);
	Data	 *mantis_clone = Serializer::deserialize(raw_mantis);

	if (centipede == centi_clone)
		cout << "Centipede was deserialized: " << centi_clone << endl;
	if (mantis == mantis_clone)
		cout << "Mantis was deserialized: " << mantis_clone << endl;

	return 0;
}
