#ifndef ICHARACTER_H_
#define ICHARACTER_H_

#include <string>
#include "AMateria.h"

class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter () {}
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_H_