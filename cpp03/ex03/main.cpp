#include <iostream>
#include "DiamondTrap.h"

signed main() {
	DiamondTrap a("test1");
	DiamondTrap b(a);
	DiamondTrap c;
	c = b;
	std::cerr << "++++++++++++++++++++++++++++++++++" << std::endl;

	a.whoAmI();
	b.whoAmI();
	c.whoAmI();

	std::cerr << "++++++++++++++++++++++++++++++++++" << std::endl;
	a.attack("test of a");
	b.attack("test of b");
	c.attack("test of c");
}