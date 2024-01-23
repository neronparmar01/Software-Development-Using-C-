// Name: Neron Parmar
// Student ID: 171690217
// File: File.h
// Date: 11/1/23
// All the work in the workshop and coding is done by my own and no part of my workshop is copied or shared to anyone.

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <iostream>
#include <cstring>
#include <string>
#include "Resource.h"

namespace sdds {
	class File : public Resource {
		std::string m_contents{};

	public:
		File(const std::string& name, const std::string& contents = "");
		void update_parent_path(const std::string&);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
	};
}
#endif // !SDDS_FILE_H
