#include "ClapTrap.h"

signed main() {
	ClapTrap a("test1");
	ClapTrap b(a);
	ClapTrap c;
	c = b;

	a.attack("tmp");
	a.beReapaired(123456789);
	a.takeDamage(42);

	b.attack("tmp");
	b.takeDamage(42);
	b.attack("tmp");

	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.attack("tmp");
	c.beReapaired(123456789);
	c.takeDamage(42);

}