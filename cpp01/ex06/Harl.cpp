#include <iostream>
#include <map>
#include "Harl.h"

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
	const size_t MAX_LOG_LEVEL = 4;
	const std::string logs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t log_level = 0;

	for (; log_level<MAX_LOG_LEVEL; log_level++) {
		if (level == logs[log_level])
			break;
	}

	switch(log_level) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
