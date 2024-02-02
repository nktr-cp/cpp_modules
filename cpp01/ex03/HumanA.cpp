#include <iostream>
#include "HumanA.h"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name_(name), weapon_(weapon) {}	

void HumanA::attack() const {
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType() << std::endl;
}
