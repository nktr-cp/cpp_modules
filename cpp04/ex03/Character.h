#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "ICharacter.h"

class Character : public ICharacter {
	private:
		std::string name_;
		AMateria* inventory_[4];
	public:
		Character();

		Character(const Character&);

		Character(const std::string&);

		Character& operator=(const Character&);

		~Character();

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif // CHARACTER_H_