/*
Name       : Neron Parmar
Student Id : 171690217
File       : CheeseParty.h
Date       : 10/7/23

I have done the entire workshop by my own and no part of my workshop has been shared.
*/

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include <iostream>
#include "Cheese.h"

namespace sdds {
    class CheeseParty {
        const Cheese** Cheeses{};
        unsigned m_numCheeses{};

    public:
        CheeseParty();
        ~CheeseParty();
        CheeseParty(const CheeseParty& other);
        CheeseParty(CheeseParty&& other) noexcept;
        CheeseParty& operator=(const CheeseParty& other);
        CheeseParty& operator=(CheeseParty&& other) noexcept;

        void emptyParty();
        operator bool();
        void removeAndSlice(const unsigned index);
        std::ostream& print(std::ostream& os) const;
        int findEmptyCheese();
        CheeseParty& addCheese(const Cheese& addNewCheese);
        CheeseParty& removeCheese();
        friend std::ostream& operator<<(std::ostream& os, const CheeseParty& party);
    };
}

#endif // !SDDS_CHEESE_PARTY_H
