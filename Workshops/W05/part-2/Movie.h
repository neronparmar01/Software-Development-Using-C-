#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {
	class Movie {
		std::string m_movieTitle{};
		size_t m_yearOfRelease{};
		std::string m_movieDescription{};

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie); 
		//template 
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_movieTitle);
			spellChecker(m_movieDescription);
		}
		std::ostream& print(std::ostream& os)const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif // !SDDS_MOVIE_H
