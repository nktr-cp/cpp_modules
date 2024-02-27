#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
	protected:
		std::string type_;

	public:
		Animal();

		Animal(const Animal&);

		virtual ~Animal();

		Animal& operator=(const Animal&);

		virtual void makeSound() const;
		const std::string& getType() const;
};

#endif // ANIMAL_H_