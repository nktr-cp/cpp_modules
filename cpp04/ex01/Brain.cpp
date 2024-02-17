#include <iostream>
#include "Brain.h"

Brain::Brain() : number_of_ideas_(0) {
	std::cerr << "Brain class constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cerr << "Brain class copy constructor called." << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cerr << "Brain class copy assignment called." << std::endl;
	if (this == &other) {
		return *this;
	}

	for (int i=0; i<MAX_IDEAS; i++) {
		this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cerr << "Brain class destrcutor called." << std::endl;
}

std::string Brain::getIdea(const int& index) const {
	if (index >= this->number_of_ideas_) {
		std::cout << "No matching idea." << std::endl;
		exit(1);
	}

	return this->ideas[index];
}

void Brain::setIdea(const std::string& idea) {
	if (this->number_of_ideas_ >= MAX_IDEAS) {
		std::cout << "The brain is already full of ideas...!" << std::endl;
		return;
	}

	this->ideas[this->number_of_ideas_] = idea;
	this->number_of_ideas_++;
}
