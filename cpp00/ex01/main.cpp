#include <iostream>
#include <string>
#include "PhoneBook.h"

static bool _is_number(const std::string& s) {
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) it++;
	return (!s.empty() && it == s.end());
}

static void _process_input(std::string& s) {
	std::getline(std::cin, s);
	if (std::cin.fail() || std::cin.eof()) {
		std::cout << std::endl;
		std::cout << "EOF detected." << std::endl;
		exit(EXIT_FAILURE);
	}
}

static void _search(PhoneBook &phonebook) {
	if (phonebook.get_entry_count() == 0) {
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}

	phonebook.show();

	std::string s_index;
	std::cout << "Enter index: ";
	std::cin >> s_index;
	if (std::cin.eof()) {
		std::cout << std::endl << "EOF detected." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail() || !_is_number(s_index)) {
		std::cout << "Invalid input" << std::endl;
		std::cin.clear();
		return;
	}
	int index = std::atoi(s_index.c_str());
	if (index >= phonebook.get_entry_count()) {
		std::cout << "Given index is out of range" << std::endl;
		return;
	}
	phonebook.show_contact(index);
}

static void _add(PhoneBook &phonebook) {
	bool invalid = false;
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	std::cout << "Enter first name: ";
	_process_input(first_name);
	invalid |= first_name.empty();
	std::cout << "Enter last name: ";
	_process_input(last_name);
	invalid |= last_name.empty();
	std::cout << "Enter nickname: ";
	_process_input(nickname);
	invalid |= nickname.empty();
	std::cout << "Enter phone number: ";
	_process_input(phone_number);
	invalid |= phone_number.empty();
	std::cout << "Enter darkest secret: ";
	_process_input(darkest_secret);
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
			exit(EXIT_FAILURE);
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
