#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include<iostream>
#include<string>
#include <iomanip>
#include <fstream>
#define NUMBER_OF_WORDS 6

namespace sdds {
	class SpellChecker {
		std::string m_badWords[NUMBER_OF_WORDS]{};
		std::string m_goodWords[NUMBER_OF_WORDS]{};
		int m_count[NUMBER_OF_WORDS]{};

	public:
		SpellChecker() {};
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
