#ifndef HUMAN_B_H_
#define HUMAN_B_H_

#include <string>
#include "Weapon.h"

class HumanB {
	private:
		std::string name_;
		// this data should be pointer to be nullable
		Weapon *weapon_;

	public:
		HumanB(const std::string&);

		// HumanB(const HumanB &);

		// ~HumanB();

		// HumanB &operator=(const HumanB &);

		void attack() const;
		void setWeapon(Weapon &);
};

#endif // HUMAN_B_H_