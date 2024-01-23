/*
Name       : Neron Parmar
Student Id : 171690217
File       : CheeseShop.cpp
Date       : 10/7/23

I have done the entire workshop by my own and no part of my workshop has been shared.
*/

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H

#include <iostream>
#include <string>
#include "Cheese.h"

namespace sdds
{
    class CheeseShop
    {
        std::string m_name;
        unsigned m_numCheeses;
        const Cheese** m_cheeses;

    public:
        CheeseShop(const std::string& name = "No Name");
        CheeseShop(const CheeseShop& other);
        CheeseShop& operator=(const CheeseShop& other);
        CheeseShop(CheeseShop&& other) noexcept;
        CheeseShop& operator=(CheeseShop&& other) noexcept;
        ~CheeseShop();

        CheeseShop& addCheese(const Cheese& cheese);
        void emptyShop();
        operator bool() const;
        std::ostream& print(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, const CheeseShop& shop);
    };
}

#endif // !SDDS_CHEESESHOP_H
