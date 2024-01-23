// Name: Neron Parmar
// Student ID: 171690217
// File: Directory.cpp
// Date: 11/1/23
// All the work in the workshop and coding is done by my own and no part of my workshop is copied or shared to anyone.

#define _CRT_SECURE_NO_WARNINGS
#include "Directory.h"

using namespace std;
namespace sdds {
	Directory::Directory(const std::string& name) {
		m_name = name;
		if (!m_name.empty() && m_name.back() != '/')
			m_name += "/";
	}

	void Directory::update_parent_path(const std::string& path) {
		m_parent_path = path;
		for (auto& resource : m_contents) {
			resource->update_parent_path(m_parent_path + m_name);
		}
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::path()const {
		return m_parent_path + m_name;
	}

	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return static_cast<int>(m_contents.size());
	}

	size_t Directory::size() const {
		size_t totalSize = 0u;

		for (auto& resource : m_contents) {
			totalSize += resource->size();
		}

		return totalSize;
	}

	Directory& Directory::operator+=(Resource* resource) {
		for (Resource* res : m_contents) {
			if (res) {
				if (res->name() == resource->name()) {
					throw std::runtime_error("Error...! Resource with the same name already exists...");
				}
			}
		}
		resource->update_parent_path(path());
		m_contents.push_back(resource);
		return *this;
	}

	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
		auto Flag = std::find_if(flags.begin(), flags.end(), [](OpFlags flag) {
			return flag == OpFlags::RECURSIVE;
			});

		if (Flag != flags.end()) {
			for (auto& resource : m_contents) {
				if (resource->type() == NodeType::DIR) {
					auto findResource = dynamic_cast<Directory*>(resource)->find(name, flags);
					if (findResource != nullptr) {
						return findResource;
					}
				}
			}
		}

		for (auto& resource : m_contents) {
			if (resource->name() == name) {
				return resource;
			}
		}
		return nullptr;
	}

	Directory::~Directory() {
		for (auto& Resource : m_contents) {
			delete Resource;
		}
		m_contents.clear();
	}
}