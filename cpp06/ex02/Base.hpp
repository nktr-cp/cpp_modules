#ifndef BASE_HPP_
#define BASE_HPP_

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base {
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base*);
void identify(Base&);

#endif // BASE_HPP_
