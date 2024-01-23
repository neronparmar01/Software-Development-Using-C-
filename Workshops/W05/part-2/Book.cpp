// Name : Neron Parmar
// Student ID : 171690217
// File :: Book.cpp
// All the work in this workshop is done by my own and no part of this workshop is shared with anyone.

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;
namespace sdds {
	const string& Book::title()const {
		return m_title;
	}

	const string& Book::country()const {
		return m_country;
	}

	const size_t& Book::year()const {
		return m_pubYear;
	}

	double& Book::price() {
		return m_price;
	}

	double Book::validatePrice(const std::string& priceString) {
		std::istringstream ss(priceString);
		double price = 0.0;
		ss >> price;

		if (ss.fail() || !ss.eof()) {
			throw "Invalid price string";
		}

		return price;
	}

	Book::Book(const std::string& strBook)
	{
		string temp{};
		string str = strBook;
		size_t delimiter{};

		// Parse the input string using ',' as a delimiter
		delimiter = str.find_first_of(',');
		temp = str.substr(0, delimiter);
		m_author = trimToken(temp);
		str.erase(0, delimiter + 1);
		delimiter = str.find_first_of(',');
		temp = str.substr(0, delimiter);
		m_title = trimToken(temp);
		str.erase(0, delimiter + 1);
		delimiter = str.find_first_of(',');
		temp = str.substr(0, delimiter);
		m_country = trimToken(temp);
		str.erase(0, delimiter + 1);
		delimiter = str.find_first_of(',');
		temp = str.substr(0, delimiter);
		m_price = validatePrice(trimToken(temp));
		str.erase(0, delimiter + 1);
		delimiter = str.find_first_of(',');
		temp = str.substr(0, delimiter);
		temp = trimToken(temp);
		m_pubYear = stoi(temp);
		str.erase(0, delimiter + 1);
		delimiter = str.find_first_of('\n');
		temp = str.substr(0, delimiter);
		m_description = trimToken(temp);
	}

	std::string Book::trimToken(std::string& token)
	{
		size_t trimmed = 0;
		while (isspace(token[trimmed]) && trimmed < token.length())
			trimmed++;

		token = token.erase(0, trimmed);

		trimmed = token.length() - 1;
		// Trim trailing whitespace
		while (isspace(token[trimmed]) && trimmed > 0)
			trimmed--;

		if (trimmed < token.length() - 1)
			token = token.erase(trimmed + 1, token.length());

		return token;
	}

	std::ostream& Book::print(std::ostream& os) {
		os << setw(20) << m_author << " | "
			<< setw(22) << m_title << " | "
			<< setw(5) << m_country << " | "
			<< setw(4) << m_pubYear << " | "
			<< setw(6) << setprecision(2) << setiosflags(ios::fixed) << m_price << " | "			// error in price solved by formatting
			<< m_description;

		return os;
	}


	std::ostream& operator<<(std::ostream& os, Book& books)
	{
		return books.print(os);
	}

}