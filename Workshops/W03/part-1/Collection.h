// Workshop 3 - Templates
// Created by: Jeevan Pant
// Date created: 2023/07/22
/* Name       : Neron Parmar
*  Student ID : 171690217
*  File       : Collection.h
*  Date       : 9/30/23
*  All the work is done by me and none of the part or none of the file is shared to anyone or
*  no part is copied and enitre workshop is done by my own.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Book.h"

namespace sdds {
	template <typename T, unsigned A>
	class Collection {
		T m_items[A];
		static T m_smallestItem;
		static T m_largestItem;
		std::size_t m_size;

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


		Collection() :m_size(0) {};
		T getSmallestItem() {
			std::cout.precision(1);			// get exact precise decimal for the double values
			return m_smallestItem;
		}
		T getLargestItem() {
			return m_largestItem;
		}
		std::size_t size() const {
			return m_size;
		}
		std::size_t capacity() const {
			return A;
		}
		bool operator+=(const T& item) {
			if (m_size < A) {
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
			for (std::size_t i = 0; i < m_size; ++i) {
				os << m_items[i];
				if (i != m_size - 1) {
					os << ',';
				}
			}
			os << "]" << std::endl;
		}
	};

	template <typename T, unsigned A>
	T Collection<T, A>::m_smallestItem = 10;

	template <typename T, unsigned A>
	T Collection<T, A>::m_largestItem = -10;

	template<>
	Book Collection<Book, 10>::m_smallestItem = Book{ "", 10000, 1 };

	template<>
	Book Collection<Book, 10>::m_largestItem = Book{ "", 1, 10000 };
}
#endif // !SDDS_COLLECTION_H


