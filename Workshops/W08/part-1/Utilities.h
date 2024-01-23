// Workshop 8 - Smart Pointers
// Name : Neron Parmar
// Student ID : 171690217
// File : Utilities.h
// Date : 11/17/23
// All the work in the workshop is done by my own and no part of the workshop is copied or shared with anyone.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "DataBase.h"
#include "Profile.h"

namespace sdds
{
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles);
}

#endif