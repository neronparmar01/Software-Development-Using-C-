// Name : Neron Parmar
// Student ID : 171690217
// Date : 11/11/23
// File : Utilities.h
// All the work in the milestone is done by my own and no part of the milestone is shared to anyone.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds {

	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;

	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !SDDS_UTILITIES_H
