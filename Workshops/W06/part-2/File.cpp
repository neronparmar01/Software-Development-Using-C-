// Name: Neron Parmar
// Student ID: 171690217
// File: File.cpp
// Date: 11/1/23
// All the work in the workshop and coding is done by my own and no part of my workshop is copied or shared to anyone.

#define _CRT_SECURE_NO_WARNINGS
#include "File.h"

using namespace std;
namespace sdds {
	File::File(const std::string& name, const std::string& contents) : m_contents(contents) {
		m_name = name;
	}

	void File::update_parent_path(const std::string& path) {
		m_parent_path = path;
	}

	NodeType File::type() const {
		return NodeType::FILE;
	}

	std::string File::path()const {
		return m_parent_path + m_name;
	}

	std::string File::name()const {
		return m_name;
	}

	int File::count()const {
		return -1;
	}

	size_t File::size()const {
		return m_contents.size();
	}
}