// Name : Neron Parmar
// Student ID : 171690217
// File : CovidCollection.cpp
// Date : 11/12/23
// All the work of the workshop is done by my own and no part of workshop is copied or not part of my
// work is shared.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <limits>
#include <numeric>
#include <sstream>
#include "CovidCollection.h"

using namespace std;
namespace sdds {

	string& CovidCollection::trim(string& str) {
		bool trim = false;

		while (!trim) {
			trim = true;
			if (str.find(' ') == 0) {
				trim = false;
				str.erase(str.begin());
			}
			if (str.size() > 0 && str.substr(str.size() - 1, 1).find(' ') != std::string::npos) {
				str.erase(str.end() - 1);
				trim = false;
			}
		}
		return str;
	}

	CovidCollection::CovidCollection(const char* filename) {
		ifstream file(filename);

		if (file) {
			while (file.peek() != EOF) {
				Covid covid{};

				char temp[25 + 1];
				string token{};

				file.get(temp, 26);
				token = string(temp);
				token = trim(token);
				covid.m_country = token;

				file.get(temp, 26);
				token = string(temp);
				token = trim(token);
				covid.m_city = token;

				file.get(temp, 26);
				token = string(temp);
				token = trim(token);
				covid.m_variant = token;

				/*file.get(temp, 6);
				covid.m_year = atoi(temp);*/

				file >> covid.m_year;
				if (!file) {
					file.clear();
					file.ignore(numeric_limits<streamsize>::max(), ' ');
				}

				file.get(temp, 6);
				covid.m_cases = atoi(temp);

				file.get(temp, 6);
				covid.m_deaths = atoi(temp);

				getline(file, token);
				m_covid.push_back(covid);
			}
		}
		else {
			throw("Error...! File not found...");
		}
	}

	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| ";
		out.width(21);
		out.fill(' ');
		out << left << theCovid.m_country << " | ";
		out.width(15);
		out.fill(' ');
		out << left << theCovid.m_city << " | ";
		out.width(20);
		out.fill(' ');
		out << left << theCovid.m_variant << " | " << resetiosflags(ios::left);
		out << setw(6);
		if (theCovid.m_year > 0)
			out << theCovid.m_year << " | ";
		else
			out << " " << " | ";

		out.width(4);
		out.fill(' ');
		out << right << theCovid.m_cases << " | ";
		out.width(3);
		out.fill(' ');
		out << right << theCovid.m_deaths << " |";
		out.fill(' ');
		out << " | " << setw(8) <<  right << theCovid.m_severity << " |";


		return out;
	}

	void CovidCollection::display(std::ostream& out, const std::string& country) const {
		if (country != "ALL")
			out << "Displaying information of country = " << country << std::endl;

		size_t totalWorldCases = std::accumulate(m_covid.begin(), m_covid.end(), (size_t)0, [](const size_t& totalWorldCases, const Covid& covid)
			{
				return totalWorldCases + covid.m_cases;
			});

		size_t totalWorldDeaths = std::accumulate(m_covid.begin(), m_covid.end(), (size_t)0, [](const size_t& totalWorldDeaths, const Covid& covid)
			{
				return totalWorldDeaths + covid.m_deaths;
			});

		if (country == "ALL") {

			std::for_each(m_covid.begin(), m_covid.end(), [&out](const Covid& covid) {
				out << covid << std::endl;
				});

			out << "| " << std::setw(79) << "Total cases around the world: " << totalWorldCases << " |" << std::endl;
			out << "| " << std::setw(79) << "Total deaths around the world: " << totalWorldDeaths << " |" << std::endl;
		}
		else {

			size_t totalCases = 0;
			size_t totalDeaths = 0;

			std::for_each(m_covid.begin(), m_covid.end(), [&totalCases, &totalDeaths, &country, &out](const Covid& covid) {
				if (covid.m_country == country) {
					totalCases += covid.m_cases;
					totalDeaths += covid.m_deaths;
					out << covid << std::endl;
				}
				});

			double casePercentage = (static_cast<double>(totalCases) / totalWorldCases) * 100.0;
			double deathPercentage = (static_cast<double>(totalDeaths) / totalWorldDeaths) * 100.0;

			std::string caseToDisplay = "Total cases in " + country;
			std::string deathToDisplay = "Total deaths in " + country;

			out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
			out << "| " << std::right << std::setw(78) << caseToDisplay << ": " << std::setw(4) << totalCases << " |" << std::endl;
			out << "| " << std::right << std::setw(78) << deathToDisplay << ": " << std::setw(4) << totalDeaths << " |" << std::endl;

			// displaying the total deaths and the cases in the percentage
			std::string displayCases_Deaths = country + " has " + std::to_string(casePercentage) + "% of global cases and " + std::to_string(deathPercentage) + "% of global deaths |";
			out << "| " << std::right << std::setw(86) << displayCases_Deaths << std::endl;
		}
	}

	void CovidCollection::sort(const std::string& field) {
		std::sort(m_covid.begin(), m_covid.end(), [field](const Covid& covid, const Covid& cov)
			{
				if (field == "country" || field == "DEFAULT") {
					if (covid.m_country == cov.m_country)
						return covid.m_deaths < cov.m_deaths;
					return covid.m_country < cov.m_country;
				}
				else if (field == "year") {
					if (covid.m_year == cov.m_year)
						return covid.m_deaths < cov.m_deaths;
					return covid.m_year < cov.m_year;
				}
				else if (field == "variant") {
					if (covid.m_variant == cov.m_variant)
						return covid.m_deaths < cov.m_deaths;
					return covid.m_variant < cov.m_variant;
				}
				else {
					return false;
				}
			});

	}

	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
		return std::any_of(m_covid.begin(), m_covid.end(), [&](const Covid& covid) {
			return (covid.m_country == country) && (covid.m_variant == variant) && (covid.m_deaths > deaths);
			});
	}

	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
		list<Covid> lists{};
		copy_if(m_covid.begin(), m_covid.end(), std::back_inserter(lists), [=](const Covid& covid_s) -> bool {
			return covid_s.m_deaths >= deaths;
			});

		return lists;
	}

	void CovidCollection::updateStatus() {
		std::for_each(m_covid.begin(), m_covid.end(), [](Covid& covid_s) {
			if (covid_s.m_deaths > 300)
				covid_s.m_severity = "EPIDEMIC";
			else if (covid_s.m_deaths < 50)
				covid_s.m_severity = "EARLY";
			else
				covid_s.m_severity = "MILD";
			return covid_s.m_severity;
			});
	}
}
