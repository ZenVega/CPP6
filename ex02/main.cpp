/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:26:15 by uschmidt          #+#    #+#             */
/*   Updated: 2025/09/17 15:10:25 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A/A.hpp"
#include "B/B.hpp"
#include "Base/Base.hpp"
#include "C/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

Base *generate(void)
{
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);
	int choice = ts.tv_nsec % 3;
	switch (choice)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	default:
		return new C;
	}
};

// dynamic casts are used for safely casting a base obj to a derived obj
void identify(Base *p)
{
	// This only casts pointers, therefore no assignment operator is needed.
	if (A *a = dynamic_cast<A *>(p))
	{
		cout << "A" << endl;
		delete p;
	}
	else if (B *b = dynamic_cast<B *>(p))
	{
		cout << "B" << endl;
		delete p;
	}
	else if (C *c = dynamic_cast<C *>(p))
	{
		cout << "C" << endl;
		delete p;
	}
	else
		cout << "This should never happen" << endl;
};

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		cout << "A" << endl;
		return;
	}
	catch (std::exception e)
	{
	};
	try
	{
		(void)dynamic_cast<B &>(p);
		cout << "B" << endl;
		return;
	}
	catch (std::exception e)
	{
	};
	try
	{
		(void)dynamic_cast<C &>(p);
		cout << "C" << endl;
		return;
	}
	catch (std::exception e)
	{
	};
	cout << "This should never happen" << endl;
};

int main(void)
{
	Base *unknown_objs[10];
	for (int i = 0; i < 10; i++)
		unknown_objs[i] = generate();
	for (int i = 0; i < 10; i++)
	{
		identify(*unknown_objs[i]);
		identify(unknown_objs[i]);
	}
	return 0;
}
