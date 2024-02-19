#ifndef AANIMAL_H_
#define AANIMAL_H_

#include <string>

class AAnimal {
	protected:
		std::string type_;

	public:
		AAnimal();

		AAnimal(const AAnimal&);

		virtual ~AAnimal() = 0;

		AAnimal& operator=(const AAnimal&);

		virtual void makeSound() const;
		const std::string& getType() const;
};

#endif // AANIMAL_H_