#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie {
	private:
		std::string name_;

	public:
		Zombie();

		Zombie(const std::string name);

		Zombie(const Zombie &zombie);

		~Zombie();

		Zombie &operator=(const Zombie &zombie);

		void announce(void);
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif // ZOMBIE_H_