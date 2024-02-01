#include <iostream>
#include "Contact.h"

Contact::Contact() {}

Contact::Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
							const std::string &phone_number, const std::string &darkest_secret)
						: first_name_(first_name), last_name_(last_name), nickname_(nickname),
								phone_number_(phone_number), darkest_secret_(darkest_secret) {}

Contact::Contact(const Contact &contact) {
	*this = contact;
}

Contact::~Contact() {}

Contact &Contact::operator=(const Contact &contact) {
	if (this == &contact) {
		return (*this);
	}
	this->first_name_ = contact.first_name_;
	this->last_name_ = contact.last_name_;
	this->nickname_ = contact.nickname_;
	this->phone_number_ = contact.phone_number_;
	this->darkest_secret_ = contact.darkest_secret_;
	return *this;
}

void Contact::show_contact() const {
	std::cout << "First name: " << this->first_name_ << std::endl;
	std::cout << "Last name: " << this->last_name_ << std::endl;
	std::cout << "Nickname: " << this->nickname_ << std::endl;
	std::cout << "Phone number: " << this->phone_number_ << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret_ << std::endl;
}

std::string Contact::get_first_name() const {
	return this->first_name_;
}

std::string Contact::get_last_name() const {
	return this->last_name_;
}

std::string Contact::get_nickname() const {
	return this->nickname_;
}

std::string Contact::get_phone_number() const {
	return this->phone_number_;
}

std::string Contact::get_darkest_secret() const {
	return this->darkest_secret_;
}
