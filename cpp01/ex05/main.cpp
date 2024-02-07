#include "Harl.h"

int main() {
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	// no matching function
	harl.complain("WRONG");
	harl.complain("TEST");
	harl.complain("NOT");
	harl.complain("FOUND");
}