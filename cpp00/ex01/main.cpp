#include <iostream>
#include "PhoneBook.h"

static void _search(PhoneBook &phonebook) {
	if (phonebook.get_entry_count() == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}

	phonebook.show();

	int index;
	std::cout << "Enter index: ";
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail() || index >= phonebook.get_entry_count()) {
		std::cout << "Invalid input" << std::endl;
		return;
	}
	phonebook.show_contact(index);
}

static void _add(PhoneBook &phonebook) {
	bool invalid = false;
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	invalid |= first_name.empty();
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	invalid |= last_name.empty();
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	invalid |= nickname.empty();
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	invalid |= phone_number.empty();
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	invalid |= darkest_secret.empty();

	if (invalid) {
		std::cout << "Invalid input." << std::endl;
		return;
	}
	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
	phonebook.add_contact(contact);
}

int main() {
	PhoneBook phonebook;

	while (true) {
		std::string command;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return 0;
		if (command == "ADD") {
			_add(phonebook);
		} else if (command == "SEARCH") {
			_search(phonebook);
		} else if (command == "EXIT") {
			std::cout << "Exit phonebook." << std::endl;
			return 0;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}
}
