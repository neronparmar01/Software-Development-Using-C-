// Workshop 3 - Templates
// Created by: Jeevan Pant
// Date created: 2023/07/22
/* Name       : Neron Parmar
*  Student ID : 171690217
*  File       : Collection.h
*  Date       : 10/1/23
*  All the work is done by me and none of the part or none of the file is shared to anyone or
*  no part is copied and enitre workshop is done by my own.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds {
	template <typename T, unsigned int C>
	class Collection {
		static T m_smallestItem;
		static T m_largestItem;
		unsigned int m_size;

	protected:
		T m_items[C];		// for making accessible in order collection

	public:
		void setSmallestItem(const T& item) {
			if (item < m_smallestItem) {
				m_smallestItem = item;
			}
		}
		void setLargestItem(const T& item) {
			if (item > m_largestItem) {
				m_largestItem = item;
			}
		}

		//adding part 2 mutator operator and the increase size
		T operator[](std::size_t index) const {
			if (index < m_size) {
				return m_items[index]; 
			}
		}

		void incrSize() {
			if (m_size < C) {
				m_size++;
			}
		}

		Collection() :m_size(0) {};
		T getSmallestItem() {
			std::cout.precision(1);			// get exact precise decimal for the double values
			return m_smallestItem;
		}
		T getLargestItem() {
			return m_largestItem;
		}
		unsigned int size() const {
			return m_size;
		}
		unsigned int capacity() const {
			return C;
		}
		bool operator+=(const T& item) {
			if (m_size < C) {
				m_items[m_size++] = item;
				if (item < m_smallestItem) {
					m_smallestItem = item;
				}
				if (item > m_largestItem) {
					m_largestItem = item;
				}
				return true;
			}
			else {
				return false;
			}
		}
		void print(std::ostream& os) const {
			os << "[";
			for (unsigned int i = 0; i < m_size; ++i) {
				os << m_items[i];
				if (i != m_size - 1) {
					os << ',';
				}
			}
			os << "]" << std::endl;
		}
	};

	template <typename T, unsigned int C>
	T Collection<T, C>::m_smallestItem = 10;

	template <typename T, unsigned int C>
	T Collection<T, C>::m_largestItem = -10;

	template<>
	Book Collection<Book, 10>::m_smallestItem = Book{ "", 1, 10000 };

	template<>
	Book Collection<Book, 10>::m_largestItem = Book{ "", 10000, 1 };

	// template function
	 template<>
	 Book Collection<Book, 72>::m_smallestItem = Book{ "", 1, 10000 };

	 template<>
	 Book Collection<Book, 72>::m_largestItem = Book{ "" , 10000, 1 };

	 template<>
	 void Collection<Book,10>::print(std::ostream& os)const{
		 os << "| ---------------------------------------------------------------------------|" << std::endl;
		 for (unsigned int i = 0; i < m_size; i++) {
			 m_items[i].print(os << "| ") << " |" << std::endl;
		 }
		 os << "| ---------------------------------------------------------------------------|" << std::endl;
	 }

	 template<>
	 void Collection<Book, 72>::print(std::ostream& os) const {
		 os << "| ---------------------------------------------------------------------------|" << std::endl;
		 for (unsigned int i = 0; i < m_size; i++) {
			 m_items[i].print(os << "| ") << " |" << std::endl;
		 }
		 os << "| ---------------------------------------------------------------------------|" << std::endl;
	 }
}
#endif // !SDDS_COLLECTION_H


