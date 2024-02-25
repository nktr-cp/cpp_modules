#ifndef MATERIA_SOURCE_H_
#define MATERIA_SOURCE_H_

#include "IMateriaSource.h"

class MateriaSource : public IMateriaSource {
	private:
		std::string name_;
		AMateria* inventory_[4];
	public:
		MateriaSource();

		MateriaSource(const std::string& type);

		MateriaSource(const MateriaSource&);

		MateriaSource& operator=(const MateriaSource&);

		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const&);
};

#endif // MATERIA_SOURCE_H_