#ifndef FILE_REPLACER_H_
#define FILE_REPLACER_H_

#include <string>
#include <fstream>

class FileReplacer {
	private:
		std::string filename_;
		std::string s1_;
		std::string s2_;
		std::ifstream infile_;
		std::ofstream outfile_;

		void openFiles_(void);
		void closeFiles_(void);

	public:
		FileReplacer(const std::string &, const std::string &, const std::string &);

		void replace(void);
};

#endif // FILE_REPLACER_H_