// Workshop 2 - Summer 2023
// w2_p1.cpp
// Rania Arbash
// Name : Neron Parmar
// Date : 9/24/23
// File : AirportModels.h
// All of the coding done is my work and no work of mine is shared to anyone or on any page

#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

    struct Airport {
        std::string code{};
        std::string name{};
        std::string city{};
        std::string state{};
        std::string country{};
        double latitude = 0.0;
        double longitude = 0.0;

        Airport(); // Default constructor
        Airport(const std::string& code, const std::string& name, const std::string& city, const std::string& state, const std::string& country, double latitude, double longitude);
        bool isEmpty() const;
    };

    std::ostream& operator<<(std::ostream& os, const Airport& airport);

    class AirportLog {
        Airport* airports{};
        size_t count{};

    public:
        AirportLog();
        AirportLog(const char* filename);
        ~AirportLog();
        void addAirport(const Airport& airport);
        AirportLog findAirport(std::string state, std::string country) const;
        Airport operator[](size_t idx) const;
        operator size_t() const;

        // completion of the rule of 5
        AirportLog(const AirportLog& source);     // copy constructor
        AirportLog(AirportLog&& source)noexcept;        // move constructor
        AirportLog& operator=(const AirportLog& source);    // copy assingment operator
        AirportLog& operator=(AirportLog&& source)noexcept;     // move assignment operator
    };

} // namespace sdds

#endif // SDDS_AIRPORTMODELS_H
