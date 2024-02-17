#include <iostream>

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal d(*j);
	Animal c;
	c = *i;


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	d.makeSound();
	c.makeSound();

	delete j;
	delete i;
	return 0;
}