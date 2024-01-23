// Name : Neron Parmar
// Student ID : 171690217
// File : Utilities.h
// Date : 12/2/23
// All the work in the milestone has done by my own and no part of the work is copied or shared with anyone.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H


#include <iostream>

namespace sdds {
	class Utilities {
		size_t m_widthField{ 1 };
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
