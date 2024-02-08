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

		ClapTrap(std::string);

		ClapTrap(const ClapTrap&);

		~ClapTrap();

		ClapTrap& operator=(const ClapTrap&);

		virtual void attack(const std::string&);
		virtual void takeDamage(unsigned int);
		virtual void beReapaired(unsigned int);
};

#endif // CLAP_TRAP_H_