#ifndef DIAMOND_TRAP_H_
#define DIAMOND_TRAP_H_

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string name_;
	public:
		DiamondTrap();

		DiamondTrap(const std::string&);

		DiamondTrap(const DiamondTrap&);

		virtual ~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap&);

		void whoAmI();
};

#endif // DIAMOND_TRAP_H_