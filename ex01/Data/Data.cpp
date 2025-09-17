/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:27:46 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 10:35:59 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() :
	_insect_name("unknown bug"), _num_legs(3), _wings(false){};

Data::Data(string name, int num_legs, bool wings) :
	_insect_name(name), _num_legs(num_legs), _wings(wings){};

Data::Data(const Data &other) :
	_insect_name(other._insect_name), _num_legs(other._num_legs), _wings(other._wings)
{
	if (&other != this)
	{
		_insect_name = other._insect_name;
		_num_legs	 = other._num_legs;
		_wings		 = other._wings;
	}
};

Data::~Data(){};

Data &Data::operator=(const Data &other)
{
	if (&other != this)
	{
		_insect_name = other._insect_name;
		_num_legs	 = other._num_legs;
		_wings		 = other._wings;
	}
	return *this;
};
