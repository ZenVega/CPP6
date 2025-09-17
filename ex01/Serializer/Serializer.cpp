/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:51:05 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 11:42:20 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this subject, the serialization is only happening on the address of the object.
// The data itself does not change.

// reinterpret cast: It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different.
// It does not check if the pointer type and data pointed by the pointer is same or not.include "Serializer.hpp"

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
};

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
};
