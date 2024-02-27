#include <iostream>

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongCat* wrong_cat = new WrongCat();
	const WrongAnimal* wrong_i = new WrongCat();
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound(); //will output the cat sound!
	wrong_i->makeSound(); //will output the cat sound!

	delete wrong_meta;
	delete wrong_cat;
	delete wrong_i;
	return 0;
}