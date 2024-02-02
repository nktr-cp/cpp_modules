#include <iostream>
#include "HumanB.h"

HumanB::HumanB(const std::string &name) : name_(name), weapon_(NULL) {}	

void HumanB::attack() const {
	if (this->weapon_ == NULL) {
		std::cout << this->name_ << " does not yet have a weapon." << std::endl;
	}
	else {
			std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon_ = &weapon;
}
