#include <iostream>
#include <cassert>
#include "Zombie.h"

// When you want to check for memory leaks,
// use `leaks -q -atExit -- ./ex01`
int main() {
	Zombie* zombies = zombieHorde(10, "test");

	for (int i=0; i<10; i++) {
		std::cout << i << ((i == 1) ? "st" : (i == 2) ? "nd" : (i == 3) ? "rd" : "th") << " zombie announces himself.." << std::endl;
		zombies[i].announce();
	}

	delete[] zombies;
}
