#ifndef AANIMAL_H_
#define AANIMAL_H_

#include <string>

class AAnimal {
	protected:
		std::string type_;

	public:
		AAnimal();

		AAnimal(const AAnimal&);

		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal&);

		virtual void makeSound() const = 0;
		const std::string& getType() const;
};

#endif // AANIMAL_H_