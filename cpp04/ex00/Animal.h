#ifndef Animal_H_
#define Animal_H_

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

#endif // Animal_H_