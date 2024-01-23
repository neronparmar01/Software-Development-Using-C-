// Name: Neron Parmar
// Seneca Student ID: 171690217
// Seneca email: nparmar22@myseneca.ca
// Date of completion: 11/18/23
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

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


#endif 
