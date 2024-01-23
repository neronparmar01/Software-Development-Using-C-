/*
Name       : Neron Parmar
Student Id : 171690217
File       : Cheese.h
Date       : 10/3/23

I have done the entire workshop by my own and no part of my workshop has been shared.
*/

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
#include<string>
#include<iomanip>

namespace sdds {
	class Cheese {
		std::string name;
		int weight;
		double price;
		std::string features;

		std::string trim(const std::string& str) const;

	public:
		// public methods
		Cheese();
		Cheese(const std::string& str);
		Cheese slice(size_t weight);
		const std::string& getName() const;
		int getWeight() const;
		double getPrice() const;
		const std::string& getFeatures() const;

		friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese);

	};
}
#endif // !SDDS_CHEESE_H
