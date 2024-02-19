#include <iostream>
#include "ClapTrap.h"

ClapTrap::ClapTrap() : hit_points_(10), energy_point_(10), attack_damage_(0) {
	std::cerr << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name_(name), hit_points_(10), energy_point_(10), attack_damage_(0) {
	std::cerr << "Contructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cerr << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cerr << "Copy assignment called" << std::endl;
	if (this == &other) {
		return *this;
	}

	this->name_ = other.name_;
	this->hit_points_ = other.hit_points_;
	this->energy_point_ = other.energy_point_;
	this->attack_damage_ = other.attack_damage_;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cerr << "Destrutor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energy_point_ == 0 || this->hit_points_ == 0) {
		std::cout << "ClapTrap " << this->name_ << " has run out of points..." << std::endl;
		return;
	}
	this->energy_point_--;
	std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points_ < amount) {
		std::cout << "ClapTrap " << this->name_ << " died..." << std::endl;
		this->hit_points_ = 0;
		return;
	}
	this->hit_points_ -= amount;
	std::cout << "ClapTrap " << this->name_ << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beReapaired(unsigned int amount) {
	if (this->energy_point_ == 0 || this->hit_points_ == 0) {
		std::cout << "ClapTrap " << this->name_ << " has run out of points..." << std::endl;
		return;
	}
	this->energy_point_--;
	this->hit_points_ += amount;
	std::cout << "ClapTrap " << this->name_ << " has recovered " << amount << " points!" << std::endl;
}
