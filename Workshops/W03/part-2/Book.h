// Workshop 3 - Templates
// Created by: Jeevan Pant
// Date created: 2023/07/22
/* Name       : Neron Parmar
*  Student ID : 171690217
*  File       : Book.h
*  Date       : 10/1/23
*  All the work is done by me and none of the part or none of the file is shared to anyone or
*  no part is copied and enitre workshop is done by my own.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book
	{
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);
		bool isValid()const;
		std::string getTitle()const;
		unsigned getNumChapters()const;
		unsigned getNumPages() const;
		double getAveragePagesPerChapter()const;
		std::ostream& print(std::ostream& os) const;

		operator bool()const;

		Book& operator=(const Book& books);
		bool operator<(const Book& books)const;
		bool operator>(const Book& books)const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif // !SDDS_BOOK_H
