// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name : Neron Parmar
// Student ID : 171690217
// File : Utilities.h
// Date : 11/18/23
// All the work in the workshop is done by my own and no part of my workshop is copied or shared with anyone

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers

#include "DataBase.h"
#include "Profile.h"

namespace sdds
{
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles);
	DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles);
}

#endif