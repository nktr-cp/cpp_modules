#include "DiamondTrap.h"

signed main() {
	DiamondTrap a("test1");
	FragTrap b(a);
	FragTrap c;
	c = b;

	a.highFiveGuys();
	b.highFiveGuys();
	c.highFiveGuys();
}