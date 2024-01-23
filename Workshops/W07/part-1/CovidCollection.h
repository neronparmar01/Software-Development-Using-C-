// Name : Neron Parmar
// Student ID : 171690217
// File : CovidCollection.h
// Date : 11/8/23
// All the work of the workshop is done by my own and no part of workshop is copied or not part of my
// work is shared.

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

namespace sdds{
	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		int m_year;
		size_t m_cases;
		size_t m_deaths;
	};

	class CovidCollection {
	private:
		std::vector<Covid> m_covid;
		std::string& trim(std::string& str);

	public:
		CovidCollection(const char* filename);
		void display(std::ostream& os)const;
	};

	std::ostream& operator<<(std::ostream& os, const Covid& covid);
}
#endif // !SDDS_COVIDCOLLECTION_H
