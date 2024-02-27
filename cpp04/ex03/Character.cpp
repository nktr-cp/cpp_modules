#include <iostream>
#include "Character.h"

Character::Character() : name_("") {
	std::cerr << "Character default constructor called" << std::endl;
	for (int i=0; i<4; i++) {
		this->inventory_[i] = 0;
	}
}

Character::Character(const std::string& name) : name_(name) {
	std::cerr << "Character constructor called" << std::endl;
	for (int i=0; i<4; i++) {
		this->inventory_[i] = 0;
	}
}

Character::Character(const Character& other) {
	*this = other;
}

Character& Character::operator=(const Character& other) {
	if (this == &other) {
		return *this;
	}
	this->name_ = other.getName();

	for (int i=0; i<4; i++) {
		if (this->inventory_[i]) {
			delete this->inventory_[i];
		}

		if (other.inventory_[i]) {
			this->inventory_[i]	= other.inventory_[i]->clone();
		} else {
			this->inventory_[i] = 0;
		}
	}

	return *this;
}

Character::~Character() {
	std::cerr << "Character destructor called" << std::endl;
	for (int i=0; i<4; i++) {
		if (this->inventory_[i]) {
			delete this->inventory_[i];
		}
	}
}

std::string const& Character::getName() const {
	return this->name_;
}

void Character::equip(AMateria* m) {
	for (int i=0; i<4; i++) {
		if (this->inventory_[i] == 0) {
			this->inventory_[i] = m;
			return;
		}
	}
	std::cout << "Cannot equip more than four materias" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Index out of range" << std::endl;
	} else {
		this->inventory_[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Index out of range" << std::endl;
	} else {
		if (this->inventory_[idx]) {
			this->inventory_[idx]->use(target);
		} else {
			std::cout << idx << "th materia not equipped yet" << std::endl;
		}
	}
}
