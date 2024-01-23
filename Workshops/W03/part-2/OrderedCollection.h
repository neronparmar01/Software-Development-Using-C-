// Workshop 3 - Templates
// Created by: Jeevan Pant
// Date created: 2023/07/22
/* Name       : Neron Parmar
*  Student ID : 171690217
*  File       : OrderedCollection.h
*  Date       : 10/1/23
*  All the work is done by me and none of the part or none of the file is shared to anyone or
*  no part is copied and enitre workshop is done by my own.
*/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H
#include <iostream>
#include <string>
#include "Book.h"
#include "Collection.h"

namespace sdds {
    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        void operator+=(T& items) {
            if (this->size() < 72) {
                this->m_items[this->size()] = items;
                for (unsigned int i = this->size(); i > 0; i--) {
                    if (this->m_items[i - 1] > this->m_items[i]) {
                        T temp = this->m_items[i - 1];
                        this->m_items[i - 1] = this->m_items[i];
                        this->m_items[i] = temp;
                    }
                    else {
                        break;
                    }
                }

                // Increase the size of the collection
                this->incrSize();


                this->setSmallestItem(items);
                this->setLargestItem(items);
            }
        }
    };
}  
#endif  // !SDDS_ORDEREDCOLLECTION_H