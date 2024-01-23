//Name : Neron Parmar
//Student ID : 171690217
//Date: 9/13/23
//File : RideRequest.h
//
//All the work and coding in this workshop is done by me and no copy of my work is shared. 


#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>
#include <iomanip>
#include <cstring>

extern double g_taxrate;
extern double g_discount;

namespace sdds {

    class RideRequest {
        char m_customerName[11];
        char m_rideDescription[26];
        double m_rate;
        bool m_discount;

    public:
        RideRequest();
        std::istream& read(std::istream& is);
        void display() const;
    };
} // namespace sdds
#endif // SDDS_RIDEREQUEST_H
