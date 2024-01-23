// Workshop 3 - Templates
// Created by: Jeevan Pant
// Date created: 2023/07/22
/* Name       : Neron Parmar
*  Student ID : 171690217
*  File       : Book.cpp
*  Date       : 10/1/23
*  All the work is done by me and none of the part or none of the file is shared to anyone or
*  no part is copied and enitre workshop is done by my own.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iomanip>
using namespace std;
namespace sdds {

	Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

	Book::Book(const std::string& title, unsigned Chapters, unsigned Pages) : m_title(title), m_numChapters(Chapters), m_numPages(Pages) {}

	bool Book::isValid()const {
		return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
	}

	std::string Book::getTitle()const {
		return m_title;
	}

	unsigned Book::getNumChapters()const {
		return m_numChapters;
	}

	unsigned Book::getNumPages()const {
		return m_numPages;
	}

	double Book::getAveragePagesPerChapter()const {
		if (m_numChapters > 0) {
			return static_cast<double>(m_numPages) / m_numChapters;
		}

		return 0.0;
	}

	std::ostream& Book::print(std::ostream& os)const {
		if (!m_title.empty()) {
			os.setf(ios::right);
			if (m_numChapters > 9) {
				os.width(49);
			}
			else {
				os.width(50);
			}
			os << m_title;
			os << "," << m_numChapters << "," << m_numPages;
			os << " | ";
			os.unsetf(ios::right);
			os.setf(ios::left);
			os << "(" << std::fixed << std::setprecision(6) << getAveragePagesPerChapter() << ")";
			os.unsetf(ios::left);
			os.width(4);
			os << "";
		}
		else {
			os << "| Invalid book data";
		}
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk)
	{
		return bk.print(os);
	}

	Book::operator bool()const {
		return m_title[0] != '\0' && m_numChapters > 0 && m_numPages > 0;
	}

	Book& Book::operator=(const Book& books) {
		if (this != &books) {
			m_title = books.m_title;
			m_numChapters = books.m_numChapters;
			m_numPages = books.m_numPages;
		}
		return *this;
	}

	bool Book::operator<(const Book& books) const{
		return getAveragePagesPerChapter() < books.getAveragePagesPerChapter();
	}

	bool Book::operator>(const Book& books) const {
		return getAveragePagesPerChapter() > books.getAveragePagesPerChapter();
	}
}