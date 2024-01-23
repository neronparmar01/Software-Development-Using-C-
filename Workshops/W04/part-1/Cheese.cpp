/*
Name       : Neron Parmar
Student Id : 171690217
File       : Cheese.cpp
Date       : 10/3/23

I have done the entire workshop by my own and no part of my workshop has been shared.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<sstream>
#include <algorithm>
#include "Cheese.h"

using namespace std;
namespace sdds {
	Cheese::Cheese() : name{ "NaC" }, weight(0), price(0.0), features("") {}

	Cheese::Cheese(const std::string& str) {
		std::istringstream iss(str);
		std::string token;

		getline(iss, token, ',');
		name = trim(token);
		getline(iss, token, ',');
		weight = std::stoi(trim(token));
		getline(iss, token, ',');
		price = std::stod(trim(token));
		features = "";
		while (getline(iss, token, ',')) {
			if (!features.empty()) {
				features += " ";
			}
			features += trim(token);
		}
	}

	Cheese Cheese::slice(size_t weight) {
		Cheese sliced;
		if (weight <= static_cast<size_t>(this->weight)) {
			sliced.name = name;
			sliced.weight = static_cast<int> (weight);
			sliced.price = price;
			sliced.features = features;

			this->weight -= static_cast<int> (weight);
		}
		return sliced;
	}

	const std::string& Cheese::getName()const {
		return name;
	}

	int Cheese::getWeight() const {
		return weight;
	}

	double Cheese::getPrice()const {
		return price;
	}

	const std::string& Cheese::getFeatures()const {
		return features;
	}

	ostream& operator<<(std::ostream& os, const Cheese& cheese) {
		os << "|";
		os << left << setw(21) << cheese.name << "|";
		os << setw(5) << cheese.weight << "|";
		os << fixed << setprecision(2) << setw(5) << cheese.price << "|";
		os << right << setw(33) << cheese.features << " |";
		os << endl;

		return os;
	}

	std::string Cheese::trim(const std::string& str) const {
		std::string trimmed = str;

		trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](int ch) {
			return !std::isspace(ch);
		}));

		trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), trimmed.end());

		return trimmed;
	}
}