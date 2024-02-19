#include "ScavTrap.h"

signed main() {
	ScavTrap a("test1");
	ScavTrap b(a);
	ScavTrap c;
	c = b;

	a.guardGate();
	b.guardGate();
	c.guardGate();

	b.attack("test");
}