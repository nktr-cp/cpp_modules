#ifndef PHONE_BOOK_H_
#define PHONE_BOOK_H_

#include "Contact.h"

class PhoneBook {
	private:
		static const int maximum_contacts_ = 8;
		static const int maximum_colum_width_ = 10;
		static const char delimiter_ = '|';

		int contact_count_;
		int next_index_;
		Contact contacts_[maximum_contacts_];

		std::string truncate_(const std::string &) const;

	public:
		PhoneBook();

		PhoneBook(const PhoneBook &phonebook);
		
		~PhoneBook();

		PhoneBook &operator=(const PhoneBook &);

		void add_contact(const Contact &);
		int get_entry_count() const;
		void show() const;
		void show_contact(int index) const;
};

#endif // PHONE_BOOK_H_