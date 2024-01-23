//Name : Neron Parmar
//Student ID : 171690217
//Date: 9/9/23
//File : RideRequest.cpp
//
//All the work and coding in this workshop is done by me and no copy of my work is shared. 

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "RideRequest.h"
using namespace std;

double g_taxrate;
double g_discount;

namespace sdds {
	RideRequest::RideRequest() {
		m_customerName[0] = '\0';
		m_rideDescription  = nullptr;
		m_rate = 0.0;
		m_discount = false;
	}

	RideRequest::RideRequest(const RideRequest& ride)
	{
		delete[] m_rideDescription;
		m_rideDescription = nullptr;
		strcpy(m_customerName, ride.m_customerName);
		m_rideDescription = new char[strlen(ride.m_rideDescription) + 1];
		strcpy(m_rideDescription, ride.m_rideDescription);
		m_rate = ride.m_rate;
		m_discount = ride.m_discount;
	}

	RideRequest& RideRequest::operator=(const RideRequest& ride) {
		if (this != &ride) {
			delete[] m_rideDescription;
			m_rideDescription = nullptr;
			strcpy(m_customerName, ride.m_customerName);
			m_rideDescription = new char[strlen(ride.m_rideDescription) + 1];
			strcpy(m_rideDescription, ride.m_rideDescription);
			m_rate = ride.m_rate;
			m_discount = ride.m_discount;
		}
		return *this;
	}

	RideRequest::~RideRequest()
	{
		delete[] m_rideDescription;
		m_rideDescription = nullptr;
	}

	istream& RideRequest::read(istream& is) {
		if (is) {
			static int counter = 1;

			string str;
			char discount = '\0';
			is.getline(m_customerName, 11, ',');
			getline(is, str, ',');
			delete[] m_rideDescription;
			m_rideDescription = new char[str.length() + 1];
			strcpy(m_rideDescription, str.c_str());
			is >> m_rate;
			is.ignore();
			is >> discount;

			if (discount == 'Y') {
				m_discount = true;
			}
			else {
				m_discount= false;
			}

			counter++;
		}
		return is;
	}

	void RideRequest::display()const {
		static int counter = 1;
		double PriceTaxed = (m_rate * (1 + g_taxrate));
		double m1_discount = (m_rate + (m_rate * g_taxrate)) - g_discount;

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

