#include "FragTrap.h"

signed main() {
	FragTrap a("test1");
	FragTrap b(a);
	FragTrap c;
	c = b;

	a.highFiveGuys();
	b.highFiveGuys();
	c.highFiveGuys();
}