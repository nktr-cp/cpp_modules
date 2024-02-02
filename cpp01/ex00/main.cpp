#include <iostream>
#include "Zombie.h"

int main() {
	Zombie zombie1("z1");
	zombie1.announce();

	Zombie zombie2(zombie1);
	zombie2.announce();

	Zombie zombie3 = zombie2;
	zombie3.announce();

	{
		Zombie* zombie_ptr = newZombie("z2");
		zombie_ptr->announce();
	}

	randomChump("z3");
}