/*
Name       : Neron Parmar
Student Id : 171690217
File       : CheeseParty.cpp
Date       : 10/7/23

I have done the entire workshop by my own and no part of my workshop has been shared.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CheeseParty.h"
#include "Cheese.h"

using namespace std;
namespace sdds {
    CheeseParty::CheeseParty() : Cheeses(nullptr), m_numCheeses(0) {}

    CheeseParty::~CheeseParty() {
        emptyParty();
    }

    CheeseParty::CheeseParty(const CheeseParty& other) {
        *this = other;
    }

    CheeseParty::CheeseParty(CheeseParty&& other) noexcept {
        *this = std::move(other);
    }

    CheeseParty& CheeseParty::operator=(const CheeseParty& other) {
        if (this != &other) {
            emptyParty();
            m_numCheeses = other.m_numCheeses;
            Cheeses = new const Cheese * [m_numCheeses];
            for (size_t i = 0; i < m_numCheeses; i++) {
                Cheeses[i] = other.Cheeses[i];
            }
        }
        return *this;
    }

    CheeseParty& CheeseParty::operator=(CheeseParty&& other) noexcept {
        if (this != &other) {
            emptyParty();
            m_numCheeses = other.m_numCheeses;
            Cheeses = other.Cheeses;
            other.Cheeses = nullptr;
            other.m_numCheeses = 0;
        }
        return *this;
    }

    void CheeseParty::emptyParty() {
        for (size_t i = 0; i < m_numCheeses; i++) {
            Cheeses[i] = nullptr;
        }
        m_numCheeses = 0;
        delete[] Cheeses;
        Cheeses = nullptr;
    }

    CheeseParty::operator bool() {
        return m_numCheeses != 0;
    }

    void CheeseParty::removeAndSlice(const unsigned index) {
        if (index < m_numCheeses) {
            const Cheese** newCheeseParty = new const Cheese * [m_numCheeses - 1];
            for (size_t i = 0, j = 0; i < m_numCheeses - 1; i++, j++) {
                if (j == index) {
                    j++;
                }
                newCheeseParty[i] = Cheeses[j];
            }

            delete[] Cheeses;
            Cheeses = newCheeseParty;
            m_numCheeses--;
        }
    }

    ostream& CheeseParty::print(ostream& os) const {
        os << "--------------------------" << endl
            << "Cheese Party" << endl
            << "--------------------------" << endl;

        if (m_numCheeses != 0) {
            for (size_t i = 0; i < m_numCheeses; i++) {
                os << *(Cheeses[i]);
            }
            os << "--------------------------" << endl;
        }
        else {
            os << "This party is just getting started!" << endl
                << "--------------------------" << endl;
        }
        return os;
    }

    int CheeseParty::findEmptyCheese() {
        int index = -1;
        bool Empty = false;

        for (size_t i = 0; i < m_numCheeses && !Empty; i++) {
            if (Cheeses[i]->getWeight() == 0u) {
                index = i;
                Empty = true;
            }
        }

        return index;
    }

    CheeseParty& CheeseParty::addCheese(const Cheese& addNewCheese) {
        bool same = false;

        for (size_t i = 0; i < m_numCheeses && !same; i++) {
            if (Cheeses[i] == &addNewCheese) {
                same = true;
            }
        }

        if (!same) {
            const Cheese** newCheeseParty = new const Cheese * [m_numCheeses + 1];
            for (size_t i = 0; i < m_numCheeses; i++) {
                newCheeseParty[i] = Cheeses[i];
            }
            newCheeseParty[m_numCheeses] = &addNewCheese;

            delete[] Cheeses;
            Cheeses = newCheeseParty;
            m_numCheeses++;
        }

        return *this;
    }

    CheeseParty& CheeseParty::removeCheese() {
        if (*this) {
            int emptyIndex{};
            bool Empty = false;
            do {
                emptyIndex = findEmptyCheese();
                Empty = emptyIndex >= 0;
                if (Empty) {
                    removeAndSlice(emptyIndex);
                }
            } while (Empty);
        }

        return *this;
    }

    ostream& operator<<(ostream& os, const CheeseParty& party) {
        return party.print(os);
    }
}