#include <iostream>
#include "MateriaSource.h"

MateriaSource::MateriaSource() {
	std::cerr << "MateriaSource default constructor called" << std::endl;
	for (int i=0; i<4; i++) {
		this->inventory_[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this == &other) {
		return *this;
	}

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

MateriaSource::~MateriaSource() {
	std::cerr << "MateriaSource destructor called" << std::endl;
	for (int i=0; i<4; i++) {
		if (this->inventory_[i]) {
			delete this->inventory_[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* src) {
	int i = 0;
	for (; i<4; i++) {
		if (this->inventory_[i] == 0) {
			break;
		}
	}

	if (i == 4) {
		std::cerr << "Cannot learn more than four materia" << std::endl;
	} else {
		this->inventory_[i] = src;
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	int i = 0;
	for (; i<4; i++) {
		if (this->inventory_[i] && this->inventory_[i]->getType() == type) {
			break;
		}
	}

	if (i == 4) {
		std::cerr << "No matching materia" << std::endl;
		return 0;
	}

	return this->inventory_[i]->clone();
}
