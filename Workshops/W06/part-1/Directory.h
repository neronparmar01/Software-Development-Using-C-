// Name: Neron Parmar
// Student ID: 171690217
// File: Directory.h
// Date: 11/1/23
// All the work in the workshop and coding is done by my own and no part of my workshop is copied or shared to anyone.

#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Resource.h"

namespace sdds {
	class Directory : public Resource {
		std::vector<Resource*> m_contents{};
	public:
		Directory() {};
		Directory(const std::string& name);
		void update_parent_path(const std::string& path);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		Directory& operator+=(Resource* resource);
		Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
		~Directory();

		Directory(const Directory&) = delete;
		Directory& operator=(const Directory&) = delete;
		Directory(Directory&&) = delete;
		Directory& operator=(Directory&&) = delete;
	};
}
#endif // !SDDS_DIRECTORY_H
