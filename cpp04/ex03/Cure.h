#ifndef CURE_H_
#define CURE_H_

#include "AMateria.h"

class Cure : public AMateria {
	public:
		Cure();

		Cure(const Cure&);

		Cure& operator=(const Cure&);

		~Cure();

		AMateria* clone() const;
		void use(ICharacter&);
};

#endif // CURE_H_