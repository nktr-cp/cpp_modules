#ifndef CLAP_TRAP_H_
#define CLAP_TRAP_H_

#include <string>

class ClapTrap {
	protected:
		std::string name_;
		const static unsigned int clap_trap_initial_hit_points = 10;
		const static unsigned int clap_trap_initial_energy_points = 10;
		const static unsigned int clap_trap_initial_attack_damage = 0;
		unsigned int hit_points_;
		unsigned int energy_point_;
		unsigned int attack_damage_;

	public:
		ClapTrap();

		ClapTrap(std::string);

		ClapTrap(const ClapTrap&);

		~ClapTrap();

		ClapTrap& operator=(const ClapTrap&);

		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beReapaired(unsigned int);
};

#endif // CLAP_TRAP_H_