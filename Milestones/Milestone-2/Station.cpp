// Name: Neron Parmar
// Seneca Student ID: 171690217
// Seneca email: nparmar22@myseneca.ca
// Date of completion: 11/18/23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include"Utilities.h"
#include "Station.h"

using namespace std;
namespace sdds {



    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;




    Station::Station(const std::string& str) {
        Utilities util{};

        size_t next_pos = 0;
        bool more = true;
        id_generator++;
        m_stationID = id_generator;
        m_name = util.extractToken(str, next_pos, more);
        m_nextNum = std::stoul(util.extractToken(str, next_pos, more));
        m_noOfItem = std::stoul(util.extractToken(str, next_pos, more));
        if (util.getFieldWidth() > m_widthField) {
            m_widthField = util.getFieldWidth();
        }
        m_desc = util.extractToken(str, next_pos, more);
    }



    const std::string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        return m_nextNum++;
    }

    size_t Station::getQuantity() const {
        return m_noOfItem;
    }

    void  Station::updateQuantity() {
        if (m_noOfItem > 0) {
            m_noOfItem--;
        }
    }





    void Station::display(std::ostream& os, bool full) const {
        os.setf(ios::right);
        os.width(3);
        os.fill('0');
        os << m_stationID << " | ";
        os.unsetf(ios::right);

        os.setf(ios::left);
        os.width(m_widthField);
        os.fill(' ');
        os << m_name << " | ";
        os.unsetf(ios::left);

        os.setf(ios::right);
        os.width(6);
        os.fill('0');
        os << m_nextNum << " | ";

        if (full) {
            os.width(4);
            os.fill(' ');
            os << m_noOfItem << " | " << m_desc;
        }

        os << std::endl;
    }



}