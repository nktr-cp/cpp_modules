#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"

class Cat : public Animal {
	public:
		Cat();

		Cat(const Cat&);

		virtual ~Cat();

		Cat& operator=(const Cat&);
		
		virtual void makeSound() const;
};

#endif // CAT_H_