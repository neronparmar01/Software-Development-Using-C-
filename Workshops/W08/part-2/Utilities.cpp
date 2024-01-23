// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// Name : Neron Parmar
// Student ID : 171690217
// File : Utilities.cpp
// Date : 11/18/23
// All the work in the workshop is done by my own and no part of my workshop is copied or shared with anyone

#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//		   The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.
		for (size_t i = 0; i < allProfiles.size(); ++i) {
			bool isBanned = false;
			for (size_t j = 0; j < bannedProfiles.size(); ++j) {
				if (allProfiles[i].m_age == bannedProfiles[j].m_age && allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name && allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name) {
					isBanned = true;
					j = bannedProfiles.size();
				}
			}

			if (!isBanned) {
				Profile* newProfile = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
				std::string msgError = "*** Invalid Address ***";

				try {
					newProfile->validateAddress();
					result += *newProfile;
				}
				catch (...) {
					delete newProfile;
					throw msgError;
				}
				delete newProfile;
			}
		}
		return result;
	}

	DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//		   The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Smart Pointers.
		for (size_t i = 0; i < allProfiles.size(); ++i) {
			bool isBanned = false;

			for (size_t j = 0; j < bannedProfiles.size(); ++j) {
				if (allProfiles[i].m_age == bannedProfiles[j].m_age &&
					allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
					allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name) {
					isBanned = true;
					break;
				}
			}

			if (!isBanned) {
				std::unique_ptr<Profile> newProfile = std::make_unique<Profile>(
					allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);

				std::string msgError = "*** Invalid Address ***";

				try {
					newProfile->validateAddress();
					result += *newProfile;
				}
				catch (...) {
					throw msgError;
				}
			}
		}
		return result;
	}
}