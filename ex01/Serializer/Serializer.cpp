/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:51:05 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 11:37:26 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In this subject, the serialization is only happening on the address of the object.
// The data itself does not change.

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
};

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
};
