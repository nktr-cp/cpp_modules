#include "Base.hpp"
#include "ABC.hpp"

#include <string>

signed main(void) {
	int test_num = 5;
	// Random number machine generation must always be done outside the loop
	std::srand(std::time(NULL));
	for (;test_num--;) {
		Base* bs = generate();
		identify(bs);
		identify(*bs);
		delete bs;
		std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
	}

	identify(NULL);
	Base* dummy = new Base();
	identify(*dummy);
	delete dummy;
}
