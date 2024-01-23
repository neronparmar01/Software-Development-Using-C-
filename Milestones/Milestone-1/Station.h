// Name : Neron Parmar
// Student ID : 171690217
// Date : 11/11/23
// File : Station.h
// All the work in the milestone is done by my own and no part of the milestone is shared to anyone.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {
	class Station {
		int m_id = 0;
		std::string m_name = "";
		std::string m_desc = "";
		size_t m_serial_num = 0;
		size_t m_curr_items = 0;

		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station(const std::string& line);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full)const;
	};
}

#endif // !SDDS_STATION_H
