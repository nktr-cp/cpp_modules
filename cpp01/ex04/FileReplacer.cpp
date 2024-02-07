#include <iostream>
#include "FileReplacer.h"

FileReplacer::FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2)
	: filename_(filename), s1_(s1), s2_(s2) {}

void FileReplacer::openFiles_(void) {
	this->infile_.open(this->filename_);
	if (!this->infile_.is_open()) {
		std::cerr << "Error opening input file: " << this->filename_ << std::endl;
		exit(EXIT_FAILURE);
	}

	this->outfile_.open(this->filename_ + ".replace");
	if (!this->outfile_.is_open()) {
		std::cerr << "Error opening output file: " << this->filename_ + ".replace" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void FileReplacer::closeFiles_(void) {
	this->infile_.close();
	this->outfile_.close();
}

void FileReplacer::replace(void) {
	this->openFiles_();

	std::string line;
	while (std::getline(this->infile_, line)) {
		size_t pos = 0;
		while ((pos = line.find(this->s1_, pos)) != std::string::npos) {
			line = line.substr(0, pos) + this->s2_ + line.substr(pos + this->s1_.length());
			pos += this->s2_.length();
		}
		this->outfile_ << line << std::endl;
	}

	this->closeFiles_();
}