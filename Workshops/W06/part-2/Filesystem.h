// Name: Neron Parmar
// Student ID: 171690217
// File: Filesystem.h
// Date: 11/5/23
// All the work in the workshop and coding is done by my own and no part of my workshop is copied or shared to anyone.

#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "Directory.h"

namespace sdds {
	class Filesystem {
		Directory* m_root{};
		Directory* m_current{};

	public:
		Filesystem(const std::string& fileName, const std::string& path = {});
		Filesystem& operator=(Filesystem&) = delete;
		Filesystem(Filesystem&) = delete;
		Filesystem(Filesystem&&) noexcept;
		Filesystem& operator=(Filesystem&&) noexcept;
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string & = "");
		Directory* get_current_directory() const;
		~Filesystem();
	};
}
#endif // !SDDS_FILESYSTEM_H
