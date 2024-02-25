#ifndef AMATERIA_H_
#define AMATERIA_H_

#include <string>
#include "ICharacter.h"

class ICharacter;

class AMateria {
	protected:
		std::string type_;
	public:
		AMateria();

		AMateria(std::string const &);

		AMateria(const AMateria&);

		AMateria& operator=(const AMateria&);

		virtual ~AMateria();

		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_H_