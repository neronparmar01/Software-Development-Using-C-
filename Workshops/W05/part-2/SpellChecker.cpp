#define _CRT_SECURE_NO_WARNINGS
#include "SpellChecker.h"

using namespace std;
namespace sdds{
	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file)
			throw "Bad file name!";
		else {
			std::string str{ "" };
			size_t i = 0u;
			do {
				std::getline(file, str);
				if (file) {
					size_t initial = str.find(' ');
					m_badWords[i] = str.substr(0, initial);
					str.erase(0, initial);
					str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
					m_goodWords[i] = str;
					i++;
				}
			} while (file);
		}file.close();
	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < NUMBER_OF_WORDS; i++) {
			size_t pos = 0;
			while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				m_count[i]++;
				pos += m_goodWords[i].length();
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out)const {
		for (size_t i = 0; i < NUMBER_OF_WORDS; i++) {
			out << right << setw(15) << m_badWords[i] << ": " << m_count << " replacements\n";
		}
	}
}