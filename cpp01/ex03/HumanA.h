#ifndef HUMAN_A_H_
#define HUMAN_A_H_

#include <string>
#include "Weapon.h"

class HumanA {
	private:
		std::string name_;
		Weapon &weapon_;

	public:
		HumanA(const std::string&, Weapon &);

		// HumanA(const HumanA &);

		// ~HumanA();

		// HumanA &operator=(const HumanA &);

		void attack() const;
};

#endif // HUMAN_A_H_