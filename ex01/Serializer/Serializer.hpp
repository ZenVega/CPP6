/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:19:32 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 11:32:03 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../Data/Data.hpp"
#include "../includes/CONSTANTS.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	Serializer &operator=(const Serializer &other);

public:
	static uintptr_t serialize(Data *ptr);
	static Data		*deserialize(uintptr_t raw);
};
#endif
