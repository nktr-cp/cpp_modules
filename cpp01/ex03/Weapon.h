#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon {
	private:
		std::string type_;

	public:
		Weapon();

		Weapon(const std::string&);

		// Weapon(const Weapon&);

		~Weapon();

		// Weapon &Weapon::operator=(const Weapon &);

		// returns a const reference to type
		const std::string &getType(void) const;
		void setType(const std::string &);
};

#endif // WEAPON_H_