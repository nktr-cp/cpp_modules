#include <iostream>
#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(const std::string name): name_(name) {}

Zombie::Zombie(const Zombie &zombie) {
	*this = zombie;
}

Zombie::~Zombie() {
	std::cout << "Zombie destructor called." << std::endl;
}

Zombie &Zombie::operator=(const Zombie &zombie) {
	if (this == &zombie) {
		return *this;
	}
	this->name_ = zombie.name_;
	return *this;
}

void Zombie::announce() const {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


