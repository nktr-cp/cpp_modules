#ifndef SCAV_TRAP_H_
#define SCAV_TRAP_H_

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();

		ScavTrap(const std::string&);

		ScavTrap(const ScavTrap&);

		ScavTrap& operator=(const ScavTrap&);

		~ScavTrap();

		void guardGate();
		void attack(const std::string&);
};

#endif // SCAV_TRAP_H_