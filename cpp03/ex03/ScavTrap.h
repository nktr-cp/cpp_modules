#ifndef SCAV_TRAP_H_
#define SCAV_TRAP_H_

#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap {
	private:
		const static unsigned int scav_trap_initial_hit_points = 100;
		const static unsigned int scav_trap_initial_energy_points = 50;
		const static unsigned int scav_trap_initial_attack_damage = 20;
	public:
		ScavTrap();

		ScavTrap(const std::string&);

		ScavTrap(const ScavTrap&);

		ScavTrap& operator=(const ScavTrap&);

		~ScavTrap();

		void guardGate();
};

#endif // SCAV_TRAP_H_