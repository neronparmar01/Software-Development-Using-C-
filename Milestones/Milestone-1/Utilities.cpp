// Name : Neron Parmar
// Student ID : 171690217
// Date : 11/11/23
// File : Utilities.cpp
// All the work in the milestone is done by my own and no part of the milestone is shared to anyone.


#include "Utilities.h"
#include <string>
#include <algorithm>

namespace sdds {

	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string res = "";
		size_t firstPos = next_pos;

		next_pos = str.find(m_delimiter, firstPos);

		if (firstPos == next_pos) {
			more = false;
			throw "   ERROR: No token.\n";
		}
		else if (next_pos == std::string::npos) {
			more = false;
			res = str.substr(firstPos);
			m_widthField = std::max(res.length(), m_widthField);
		}
		else {
			more = true;
			res = str.substr(firstPos, next_pos - firstPos);
			m_widthField = std::max(res.length(), m_widthField);
		}
		next_pos++;
		return res;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}


}