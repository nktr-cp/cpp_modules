#ifndef BRAIN_H_
#define BRAIN_H_

#include <string>

class Brain {
	protected:
		const static int MAX_IDEAS = 100;
		int number_of_ideas_;
		std::string ideas[MAX_IDEAS];

	public:
		Brain();

		Brain(const Brain&);

		~Brain();

		Brain& operator=(const Brain&);

		std::string getIdea(const int&) const;
		void setIdea(const std::string&);
};

#endif // BRAIN_H_