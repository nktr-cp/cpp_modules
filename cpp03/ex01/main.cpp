#include "ScavTrap.h"

signed main() {
	ScavTrap a("test1");
	ScavTrap b(a);
	ScavTrap c;
	c = b;

	a.guardGate();
	b.guardGate();
	c.guardGate();

	a.beReapaired(42);
	b.attack("test");
	c.takeDamage(100);
}