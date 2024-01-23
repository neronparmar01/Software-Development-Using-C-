// Name : Neron Parmar
// Student ID : 171690217
// File : CovidCollection.h
// Date : 11/12/23
// All the work of the workshop is done by my own and no part of workshop is copied or not part of my
// work is shared.

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>

namespace sdds {

	const size_t EPIDEMIC_DEATHS = 300;
	const size_t EARLY_DEATHS = 50;

	struct Covid {
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		int m_year;
		size_t m_cases;
		size_t m_deaths;

		std::string m_severity{"General"};

	};

	class CovidCollection {
	private:
		std::vector<Covid> m_covid;
		std::string& trim(std::string& str);

	public:
		CovidCollection(const char* filename);
		void display(std::ostream& out, const std::string& country = { "ALL" }) const;
		void sort(const std::string& field = "country");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const;
		void updateStatus();
	};

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H
