#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>

class Contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;

	public:
		Contact();

		Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
							const std::string &phone_number, const std::string &darkest_secret);

		Contact(const Contact &contact);
		
		~Contact();

		Contact &operator=(const Contact &contact);

		void show_contact() const;
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;
};

#endif // CONTACT_H_