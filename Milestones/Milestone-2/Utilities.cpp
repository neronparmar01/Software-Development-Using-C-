// Name: Neron Parmar
// Seneca Student ID: 171690217
// Seneca email: nparmar22@myseneca.ca
// Date of completion: 11/18/23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds {
	char Utilities::m_delimiter{};
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;

	}




	string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string token{};
		more = false;
		string remaining = str;
		size_t found = remaining.find(m_delimiter, next_pos);
		if (found == next_pos) {

			throw "delimeter at the start position";
		}
		remaining.erase(0, next_pos);
		found = remaining.find(m_delimiter);




		if (found != string::npos) {
			size_t pos1 = remaining.find_first_not_of(" ");
			size_t pos2 = remaining.find_last_not_of(" ", found - 1);
			if (pos2 != string::npos) {

				token = remaining.substr(pos1, pos2 - pos1 + 1);
			}
			else {
				token = remaining.substr(pos1, found - pos1);
			}



			more = true;
			next_pos += (found + 1);
		}
		else {
			size_t pos1 = remaining.find_first_not_of(" ");
			token = remaining.substr(pos1);
			more = false;
		}




		if (token.length() == 0) {
			more = false;
		}
		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}


}