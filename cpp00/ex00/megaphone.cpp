#include <iostream>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i=1; i<ac; i++) {
		std::string S = av[i];
		for (size_t j=0; j<S.length(); j++) {
			S[j] = std::toupper(S[j]);
		}
		std::cout << S;
	}
	std::cout << std::endl;
}