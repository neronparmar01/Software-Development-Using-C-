// Workshop 2 - Summer 2023
// w2_p1.cpp
// Rania Arbash
// Name : Neron Parmar
// Date : 9/24/23
// File : Timer.h
// All of the coding done is my work and no work of mine is shared to anyone or on any page

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
#include <chrono>		// chrono library for the time and date
namespace sdds {
	class Timer {
		std::chrono::steady_clock::time_point s_time;
		std::chrono::steady_clock::time_point e_time;
	public:
		void start();
		long long stop();		// in nanoseconds
	};
}
#endif // !SDDS_TIMER_H
