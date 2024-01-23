// Name : Neron Parmar
// Student ID : 171690217
// File : LineManager.h
// Date : 12/2/23
// All the work in the milestone has done by my own and no part of the work is copied or shared with anyone.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <iostream>
#include <vector>
#include "Workstation.h"


namespace sdds {
	class LineManager {
		std::vector<Workstation*> m_activeLine{};
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation{};
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};



}



#endif // !SDDS_LINEMANAGER_H
