#ifndef CLAP_TRAP_H_
#define CLAP_TRAP_H_

#include <string>

class ClapTrap {
	protected:
		std::string name_;
		unsigned int hit_points_;
		unsigned int energy_point_;
		unsigned int attack_damage_;

	public:
		ClapTrap();

		ClapTrap(const std::string);

		ClapTrap(const ClapTrap&);

		~ClapTrap();

		ClapTrap& operator=(const ClapTrap&);

		void attack(const std::string&);
		void takeDamage(unsigned int);
		void beReapaired(unsigned int);
};

#endif // CLAP_TRAP_H_