/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:24:41 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 10:33:15 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
using std::string;

class Data
{
private:
public:
	string _insect_name;
	int	   _num_legs;
	bool   _wings;

	Data();
	Data(string name, int num_legs, bool wings);
	Data(const Data &other);
	~Data();
	Data &operator=(const Data &other);
};
#endif
