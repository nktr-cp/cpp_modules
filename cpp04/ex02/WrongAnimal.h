#ifndef WRONG_AAnimal_H_
#define WRONG_AAnimal_H_

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

#endif // WRONG_AAnimal_H_