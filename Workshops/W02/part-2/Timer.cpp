// Workshop 2 - Summer 2023
// w2_p1.cpp
// Rania Arbash
// Name : Neron Parmar
// Date : 9/24/23
// File : Timer.cpp
// All of the coding done is my work and no work of mine is shared to anyone or on any page

#define _CRT_SECURE_NO_WARNINGS
#include "Timer.h"
using namespace std;
namespace sdds {
	void Timer::start() {
		s_time = chrono::steady_clock::now();
	}

	long long Timer::stop() {
		e_time = chrono::steady_clock::now();
		auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(e_time - s_time).count();
		return elapsed_time;
	}
}