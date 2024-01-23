// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
// 2023/10/05 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h" // intentional

// Cheching if header guards exist and follow convention.
#ifndef SDDS_BOOK_H
#error "The header guard for 'Book.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		// upadated the code for todo
		std::ifstream booksFile(argv[1]);
		size_t i = 0u;
		if (!booksFile) {
			std::cerr << "Cannot open file: \"" << argv[1] << "\"";
			throw AppErrors::CannotOpenFile;
		}while (booksFile && i < (sizeof(library) / sizeof(library[0]))) {
			std::string temp{};
			std::getline(booksFile, temp);
			if (temp[0] != '#') {
				library[i] = sdds::Book(temp);
				i++;
			}
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// updated code for the todo
	auto price = [usdToCadRate, gbpToCadRate](sdds::Book& book) -> void
		{
			if (book.country() == "US")
			{
				book.price() *= usdToCadRate;
			}
			if (book.country() == "UK" && book.year() >= 1990 && book.year() <= 1999)
			{
				book.price() *= gbpToCadRate;
			}
		};



	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";

	// updated
	for (size_t i = 0; i < (sizeof(library) / sizeof(library[0])); i++) {
		std::cout << library[i] << std::endl;
	}


	std::cout << "-----------------------------------------\n\n";

	for (size_t i = 0; i < (sizeof(library) / sizeof(library[0])); i++)
	{
		price(library[i]);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (size_t i = 0; i < (sizeof(library) / sizeof(library[0])); i++)
	{
		std::cout << library[i] << std::endl;
	}


	std::cout << "-----------------------------------------\n";

	return cout;
}