#ifndef WRONG_CAT_H_
#define WRONG_CAT_H_

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();

		WrongCat(const WrongCat&);

		~WrongCat();

		WrongCat& operator=(const WrongCat&);
		
		void makeSound() const;
};

#endif // WRONG_CAT_H_