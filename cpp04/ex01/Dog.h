#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
	private:
		Brain* brain_;
	public:
		Dog();

		Dog(const Dog&);

		virtual ~Dog();

		Dog& operator=(const Dog&);
		
		virtual void makeSound() const;
};

#endif // DOG_H_