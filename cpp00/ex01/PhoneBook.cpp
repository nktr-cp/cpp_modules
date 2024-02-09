#include <iostream>
#include <iomanip>
#include "PhoneBook.h"

PhoneBook::PhoneBook() : contact_count_(0), next_index_(0) {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &phonebook) {
	*this = phonebook;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &phonebook) {
	if (this == &phonebook) {
		return (*this);
	}
	this->next_index_ = phonebook.next_index_;
	this->contact_count_ = phonebook.contact_count_;
	for (int i=0; i<phonebook.contact_count_; i++) {
		this->contacts_[i] = phonebook.contacts_[i];
	}
	return *this;
}

void PhoneBook::add_contact(const Contact &contact) {
	this->contacts_[this->next_index_] = contact;
	this->next_index_ = (this->next_index_ + 1) % PhoneBook::maximum_contacts_;
	if (this->contact_count_ < PhoneBook::maximum_contacts_) {
		this->contact_count_++;
	}
}

int PhoneBook::get_entry_count() const {
	return this->contact_count_;
}

std::string PhoneBook::truncate_(const std::string &org) const {
	if (org.size() < PhoneBook::maximum_colum_width_) {
		return (org);
	}
	std::string ret = org.substr(0, PhoneBook::maximum_colum_width_ - 1) + '.';
	return (ret);
}

void PhoneBook::show() const {
	std::cout << std::setw(PhoneBook::maximum_colum_width_) << "index" << this->delimiter_;
	std::cout << std::setw(PhoneBook::maximum_colum_width_) << "first name" << this->delimiter_;
	std::cout << std::setw(PhoneBook::maximum_colum_width_) << "last name" << this->delimiter_;
	std::cout << std::setw(PhoneBook::maximum_colum_width_) << "nickname" << std::endl;
	for (int i=0; i<this->contact_count_; i++) {
		std::cout << std::setw(PhoneBook::maximum_colum_width_) << i << '|';
		std::cout << std::setw(PhoneBook::maximum_colum_width_) << truncate_(this->contacts_[i].get_first_name()) << '|';
		std::cout << std::setw(PhoneBook::maximum_colum_width_) << truncate_(this->contacts_[i].get_last_name()) << '|';
		std::cout << std::setw(PhoneBook::maximum_colum_width_) << truncate_(this->contacts_[i].get_nickname()) << std::endl;
	}
}

void PhoneBook::show_contact(int index) const {
	this->contacts_[index].show_contact();
}