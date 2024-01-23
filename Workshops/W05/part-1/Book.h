// Name : Neron Parmar
// Student ID : 171690217
// File :: Book.cpp
// All the work in this workshop is done by my own and no part of this workshop is shared with anyone.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>

namespace sdds {
    class Book {
    private:
        std::string m_author{};
        std::string m_title{};
        std::string m_country{};
        size_t m_pubYear{};
        double m_price{};
        std::string m_description{};

    public:
        Book() {};
        const std::string& title() const;
        const std::string& country() const;      
        const size_t& year() const;
        double& price();
        double validatePrice(const std::string& priceString);
        Book(const std::string& strBook);


        friend std::ostream& operator<<(std::ostream& os, Book& books);

        std::string trimToken(std::string& token);
        std::ostream& print(std::ostream& os);
    };
}
#endif // BOOK_H
