//Name : Neron Parmar
//Student ID : 171690217
//Date: 9/13/23
//File : RideRequest.cpp
//
//All the work and coding in this workshop is done by me and no copy of my work is shared. 

#define _CRT_SECURE_NO_WARNINGS
#include "RideRequest.h"
using namespace std;

double g_taxrate;
double g_discount;

namespace sdds {
	RideRequest::RideRequest() {
		m_customerName[0] = '\0';
		m_rideDescription[0] = '\0';
		m_rate = 0.0;
		m_discount = false;
	}

	istream& RideRequest::read(std::istream& is) {
		if (is) {
			static int counter = 0;

			is.getline(m_customerName, 11, ',');
			is.getline(m_rideDescription, 26, ',');
			is >> m_rate;
			is.ignore(1, ',');

			char discountStatus;
			is >> discountStatus;
			if (discountStatus == 'Y') {
				m_discount = true;
			}
			else {
				m_discount = false;
			}

			counter++;
		}
		return is;
	}

	void RideRequest::display()const {
		static int counter = 1;
		double PriceTaxed = (m_rate * (1 + g_taxrate));
		double m1_discount = (m_rate + (m_rate * g_taxrate)) - g_discount ;

		if (strlen(m_customerName) == 0) {
			cout << left;
			cout << setw(2) << counter << ". "
				<< "No Ride Request" << endl;
		}
		else {
			cout << left;
			cout << setw(2) << counter << setw(2) << "." << setw(10) << m_customerName << "|" << setw(25) << m_rideDescription << "|";
			cout << setprecision(2);
			cout << fixed;
			cout << setw(12) << PriceTaxed << "|";
			cout << right;
			if (m_discount) {
				cout << setw(13) << m1_discount << endl;
			}
			else {
				cout << endl;
			}
		}
		counter++;
	}
}