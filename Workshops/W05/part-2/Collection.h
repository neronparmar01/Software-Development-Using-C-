#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {

	template <typename T>
	class Collection {
		std::string colName;
		T* colItem;
		size_t colSize;
		void (*colObserver)(const Collection<T>&, const T&) = nullptr;

	public:
		Collection(const std::string& name) : colName(name), colItem(nullptr), colSize(0) {}

		~Collection() {
			delete[] colItem;
			colItem = nullptr;
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		const std::string& name() const {
			return colName;
		}

		size_t size() const {
			return colSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			colObserver = observer;
		}

		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < colSize; i++) {
				if (colItem[i].title() == item.title()) {
					return *this;
				}
			}
			T* temp = new T[colSize + 1];
			for (size_t i = 0; i < colSize; i++) {
				temp[i] = colItem[i];
			}
			temp[colSize++] = item;
			delete[] colItem;
			colItem = temp;

			if (colObserver != nullptr) {
				colObserver(*this, item);
			}

			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= colSize) {
				std::string error = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(colSize) + "] items.";
				throw std::out_of_range(error);
			}
			return colItem[idx];
		}

		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < colSize; i++) {
				if (colItem[i].title() == title) {
					return &colItem[i];
				}
			}
			return nullptr;
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
			for (size_t i = 0; i < collection.colSize; ++i) {
				os << collection.colItem[i];
			}
			return os;
		}
	};

}

#endif // !SDDS_COLLECTION_H
