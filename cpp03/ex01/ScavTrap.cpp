#include <iostream>
#include "ScavTrap.h"

ScavTrap::ScavTrap() {
	std::cerr << "ScavTrap default constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cerr << "ScavTrap constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cerr << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cerr << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cerr << "ScavTrap copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}
	ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode..." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energy_point_ == 0 || this->hit_points_ == 0) {
		std::cout << "ScavTrap " << this->name_ << " has run out of points..." << std::endl;
		return;
	}
	this->energy_point_--;
	std::cout << "ScavTrap " << this->name_ << " attacks " << target << ", causing " << this->attack_damage_ << " points of damage!" << std::endl;
}