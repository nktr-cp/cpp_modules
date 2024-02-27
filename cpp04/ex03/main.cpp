#include <iostream>
#include "AMateria.h"
#include "Cure.h"
#include "Ice.h"
#include "Character.h"
#include "MateriaSource.h"

signed main() {
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	Character ch("alice");
	Ice *m1 = new Ice();
	Ice *m2 = new Ice();
	Cure *m3 = new Cure();
	Cure *m4 = new Cure();
	Ice *m5 = new Ice();

	ch.equip(m1);
	ch.equip(m2);
	ch.equip(m3);
	ch.equip(m4);
	// fails
	ch.equip(m5);
	delete m5;

	ch.unequip(1);
	delete m2;

	ICharacter* me = new Character("me");
	// ch.use(1,*me);
	ch.use(2,*me);
	ch.use(3,*me);
	ch.use(4,*me);

	delete me;
}
