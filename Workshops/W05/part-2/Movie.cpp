#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"

using namespace std;
namespace sdds {
	Movie::Movie() {
		m_movieTitle = "",
		m_yearOfRelease = -1;
		m_movieDescription = "";
	}

	const std::string& Movie::title()const {
		return this->m_movieTitle;
	}

	Movie::Movie(const std::string& strMovie) {
		int heading = strMovie.find(',');
		this->m_movieTitle = strMovie.substr(0, heading);
		this->m_movieTitle.erase(0, this->m_movieTitle.find_first_not_of(" "));
		this->m_movieTitle.erase(this->m_movieTitle.find_last_not_of(" ") + 1);
		int theYearOfMovie = strMovie.find(',', heading + 1);
		this->m_yearOfRelease = stod(strMovie.substr(heading + 1, theYearOfMovie - heading - 1));
		int desc = strMovie.find('.', theYearOfMovie + 1);
		this->m_movieDescription = strMovie.substr(theYearOfMovie + 1, desc - theYearOfMovie + 1);
		this->m_movieDescription.erase(0, m_movieDescription.find_first_not_of(" "));
	}

	ostream& Movie::print(std::ostream& os)const {
		os << setw(40) << this->m_movieTitle << " | " << setw(4) << this->m_yearOfRelease << " | "
			<< this->m_movieDescription << endl;

		return os;
	}

	ostream& operator<<(std::ostream& os, const Movie& movie) {
		movie.print(os);
		return os;
	}
}