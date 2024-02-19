#include <iostream>
#include "FragTrap.h"

FragTrap::FragTrap() {
	std::cerr << "FragTrap default constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_point_ = 100;
	this->attack_damage_ = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cerr << "FragTrap constructor called" << std::endl;
	this->hit_points_ = 100;
	this->energy_point_ = 100;
	this->attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other) {
	std::cerr << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap() {
	std::cerr << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cerr << "FragTrap copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}
	ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << this->name_ << " requests a high five guys! Give me five, guys!" << std::endl;
}
