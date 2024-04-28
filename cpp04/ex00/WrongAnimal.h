#ifndef WRONG_ANIMAL_H_
#define WRONG_ANIMAL_H_

#include <string>

class WrongAnimal {
	protected:
		std::string type_;

	public:
		WrongAnimal();

		WrongAnimal(const WrongAnimal&);

		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal&);

		void makeSound() const;
		const std::string& getType() const;
};

#endif // WRONG_ANIMAL_H_