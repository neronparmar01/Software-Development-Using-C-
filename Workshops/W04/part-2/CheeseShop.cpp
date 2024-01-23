/*
Name       : Neron Parmar
Student Id : 171690217
File       : CheeseShop.cpp
Date       : 10/7/23

I have done the entire workshop by my own and no part of my workshop has been shared.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CheeseShop.h"

namespace sdds
{
    CheeseShop::CheeseShop(const std::string& name)
        : m_name(name), m_numCheeses(0), m_cheeses(nullptr) {}

    CheeseShop::CheeseShop(const CheeseShop& other)
        : m_name(other.m_name), m_numCheeses(other.m_numCheeses), m_cheeses(nullptr)
    {
        if (other.m_cheeses)
        {
            m_cheeses = new const Cheese * [m_numCheeses];
            for (unsigned i = 0; i < m_numCheeses; ++i)
            {
                m_cheeses[i] = new Cheese(*(other.m_cheeses[i]));
            }
        }
    }

    CheeseShop& CheeseShop::operator=(const CheeseShop& other)
    {
        if (this != &other)
        {
            emptyShop();
            m_name = other.m_name;
            m_numCheeses = other.m_numCheeses;
            if (other.m_cheeses)
            {
                m_cheeses = new const Cheese * [m_numCheeses];
                for (unsigned i = 0; i < m_numCheeses; ++i)
                {
                    m_cheeses[i] = new Cheese(*(other.m_cheeses[i]));
                }
            }
        }
        return *this;
    }

    CheeseShop::CheeseShop(CheeseShop&& other) noexcept
        : m_name(std::move(other.m_name)), m_numCheeses(other.m_numCheeses), m_cheeses(other.m_cheeses)
    {
        other.m_name = "";
        other.m_numCheeses = 0;
        other.m_cheeses = nullptr;
    }

    CheeseShop& CheeseShop::operator=(CheeseShop&& other) noexcept
    {
        if (this != &other)
        {
            emptyShop();
            m_name = std::move(other.m_name);
            m_numCheeses = other.m_numCheeses;
            m_cheeses = other.m_cheeses;

            other.m_name = "";
            other.m_numCheeses = 0;
            other.m_cheeses = nullptr;
        }
        return *this;
    }

    CheeseShop::~CheeseShop()
    {
        emptyShop();
    }

    CheeseShop& CheeseShop::addCheese(const Cheese& cheese)
    {
        const Cheese** newCheeses = new const Cheese * [m_numCheeses + 1];
        for (unsigned i = 0; i < m_numCheeses; ++i)
        {
            newCheeses[i] = m_cheeses[i];
        }
        newCheeses[m_numCheeses] = new Cheese(cheese);
        delete[] m_cheeses;
        m_cheeses = newCheeses;
        m_numCheeses++;
        return *this;
    }

    void CheeseShop::emptyShop()
    {
        if (m_cheeses)
        {
            for (unsigned i = 0; i < m_numCheeses; ++i)
            {
                delete m_cheeses[i];
            }
            delete[] m_cheeses;
            m_cheeses = nullptr;
            m_numCheeses = 0;
        }
    }

    CheeseShop::operator bool() const
    {
        return m_cheeses != nullptr;
    }

    std::ostream& CheeseShop::print(std::ostream& os) const
    {
        os << "--------------------------" << std::endl
            << m_name << std::endl
            << "--------------------------" << std::endl;

        if (*this)
        {
            for (unsigned i = 0; i < m_numCheeses; ++i)
            {
                os << *(m_cheeses[i]);
            }
            os << "--------------------------" << std::endl;
        }
        else
        {
            os << "This shop is out of cheese!" << std::endl
                << "--------------------------" << std::endl;
        }
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const CheeseShop& shop)
    {
        return shop.print(os);
    }
}
