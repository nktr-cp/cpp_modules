#include <iostream>
#include <map>
#include "Harl.h"

void Harl::debug( void ) {
	std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	typedef void (Harl::*FuncPtr)();
	std::map<std::string, FuncPtr> table;

	table["DEBUG"] = &Harl::debug;
	table["INFO"] = &Harl::info;
	table["WARNING"] = &Harl::warning;
	table["ERROR"] = &Harl::error;

	std::map<std::string, FuncPtr>::iterator itr = table.find(level);
	if (itr != table.end()) {
		(this->*(itr->second))();
	} else {
		std::cout << "Unknown complaint level: " << level << std::endl;
	}
}
