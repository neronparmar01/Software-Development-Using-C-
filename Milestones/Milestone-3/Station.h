// Name : Neron Parmar
// Student ID : 171690217
// File : Station.h
// Date : 12/2/23
// All the work in the milestone has done by my own and no part of the work is copied or shared with anyone.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>


namespace sdds {
	class Station {
		int m_stationID{};
		std::string m_name{};
		std::string m_desc{};
		size_t m_nextNum{};
		size_t m_noOfItem{};
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}


#endif // !SDDS_STATION_H
