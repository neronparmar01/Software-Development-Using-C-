// Name : Neron Parmar
// Student ID : 171690217
// File : CovidCollection.cpp
// Date : 11/8/23
// All the work of the workshop is done by my own and no part of workshop is copied or not part of my
// work is shared.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <limits>
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

	void CovidCollection::display(ostream& os) const {
		for (auto i = m_covid.cbegin(); i < m_covid.cend(); i++)
		{
			os << *i << endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Covid& covid) {
		os << "| ";
		os.width(21);
		os.fill(' ');
		os << left << covid.m_country << " | ";
		os.width(15);
		os.fill(' ');
		os << left << covid.m_city << " | ";
		os.width(20);
		os.fill(' ');
		os << left << covid.m_variant << " | " << resetiosflags(ios::left);
		os << setw(6);
		if (covid.m_year > 0)
			os << covid.m_year << " | ";
		else
			os << " " << " | ";

		os.width(4);
		os.fill(' ');
		os << right << covid.m_cases << " | ";
		os.width(3);
		os.fill(' ');
		os << right << covid.m_deaths << " |";


		return os;
	}
}
