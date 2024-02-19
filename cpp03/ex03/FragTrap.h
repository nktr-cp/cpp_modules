#ifndef FRAG_TRAP_H_
#define FRAG_TRAP_H_

#include "ScavTrap.h"

class FragTrap : public virtual ClapTrap {
	public:
		FragTrap();

		FragTrap(const std::string&);

		FragTrap(const FragTrap&);

		FragTrap& operator=(const FragTrap&);

		~FragTrap();

		void highFiveGuys(void);
};

#endif // FRAG_TRAP_H_