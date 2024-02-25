#ifndef IMATERIA_SOURCE_H_
#define IMATERIA_SOURCE_H_

#include "AMateria.h"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const&) = 0;
};

#endif // IMATERIA_SOURCE_H_