#include "FragTrap.h"

signed main() {
	FragTrap a("test1");
	FragTrap b(a);
	FragTrap c;
	c = b;

	a.highFiveGuys();
	b.highFiveGuys();
	c.highFiveGuys();

	a.attack("tmp");
	b.beReapaired(42);
	c.takeDamage(42);
}