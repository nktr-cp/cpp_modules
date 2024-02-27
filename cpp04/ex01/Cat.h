#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
	private:
		Brain* brain_;
	public:
		Cat();

		Cat(const Cat&);

		~Cat();

		Cat& operator=(const Cat&);
		
		virtual void makeSound() const;
		void setIdea(const std::string&);
		void getIdea(const int&);
};

#endif // CAT_H_