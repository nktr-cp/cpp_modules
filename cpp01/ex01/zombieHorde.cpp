#include <iostream>
#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombies = new Zombie[N];
	for (int i=0; i<N; i++) {
		zombies[i].setname(name);
	}
	return zombies;
}
