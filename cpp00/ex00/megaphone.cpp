#include <iostream>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i=1; i<ac; i++) {
		std::string S = av[i];
		std::transform(S.begin(), S.end(), S.begin(), ::toupper);
		std::cout << S;
	}
	std::cout << std::endl;
}