#include <iostream>
#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() {
	std::cerr << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : name_(name + "_clap_name") {
	std::cerr << "DiamondTrap constructor called" << std::endl;
	this->hit_points_ = FragTrap::hit_points_;
	this->energy_point_ = ScavTrap::energy_point_;
	this->attack_damage_ = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	std::cerr << "DiamondTrap copy construcor called" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap() {
	std::cerr << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cerr << "DiamondTrap copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}

	this->name_ = other.name_;
	this->hit_points_ = other.hit_points_;
	this->energy_point_ = other.energy_point_;
	this->attack_damage_ = other.energy_point_;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "Mon nom est DiamondTrap " << this->name_ << std::endl;
}