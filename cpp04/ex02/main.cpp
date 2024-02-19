#include <iostream>

#include "AAnimal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	const Dog d(*j);
	Cat c;
	c = *i;

	// error
	// const AAnimal* j = new Dog();
	// const AAnimal* i = new Cat();
	// const AAnimal d(*j);
	// AAnimal c;
	// c = *i;


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