#include "Weapon.h"

Weapon::Weapon() {}

Weapon::Weapon(const std::string &type) : type_(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void) const {
	return this->type_;
}

void Weapon::setType(const std::string &type) {
	this->type_ = type;
}
