//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Oluwaseun Kamil Oseni
//ID: 168216216
//Email: ooseni2@myseneca.ca
//Date 11/03/2023


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "HealthCard.h"
using namespace std;

namespace sdds {

    // Function to check if the health card ID is valid
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
    {
        // Check various conditions for validity
        return name && name[0] && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
    }

    // Function to set the health card to an empty state
    void HealthCard::setEmpty()
    {
        delete[] m_name;
        m_name = nullptr;
    }

    // Function to allocate memory and copy a name into the health card
    void HealthCard::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    // Function to extract a character from an input stream and handle errors
    void HealthCard::extractChar(istream& istr, char ch) const
    {
        if (istr.peek() == ch)
            istr.ignore();
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    // Function to print health card ID information to an output stream
    ostream& HealthCard::printIDInfo(ostream& ostr) const
    {
        return ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
    }

    // Function to set the health card's data
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        delete[] m_name;
        m_name = nullptr;
        setEmpty();

        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
    }

    // Constructor for the HealthCard class
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        set(name, number, vCode, sNumber);
    }

    // Copy constructor for the HealthCard class
    HealthCard::HealthCard(const HealthCard& hc)
    {
        *this = hc;
    }

    // Assignment operator for the HealthCard class
    HealthCard& HealthCard::operator=(const HealthCard& hc)
    {
        if (this != &hc)
        {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }

    // Destructor for the HealthCard class
    HealthCard::~HealthCard()
    {
        delete[] m_name;
    }

    // Conversion operator to check if the health card is valid
    HealthCard::operator bool() const
    {
        return m_name != nullptr;
    }

    // Function to read health card data from an input stream
    istream& HealthCard::read(istream& istr)
    {
        char name[MaxNameLength]{ '\0' };
        long long number{ 0 };
        char vCode[3]{ 0 };
        char sNumber[10]{ 0 };

        // Read data from the input stream and validate it
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');

        if (istr)
        {
            set(name, number, vCode, sNumber);
        }
        else
        {
            istr.clear();
            istr.ignore(1000, '\n');
        }

        return istr;
    }

    // Function to print health card data to an output stream
    ostream& HealthCard::print(ostream& ostr, bool toFile) const
    {
        if (*this)
        {
            if (toFile)
            {
                ostr << m_name;
                ostr << ',';
                printIDInfo(ostr);
                ostr << endl;
            }
            else
            {
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printIDInfo(ostr);
            }
        }

        return ostr;
    }

    // Overloaded stream extraction operator for HealthCard
    istream& operator>>(istream& istr, HealthCard& hc)
    {
        return hc.read(istr);
    }

    // Overloaded stream insertion operator for HealthCard
    ostream& operator<<(ostream& ostr, const HealthCard& hc)
    {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }

        return ostr;
    }
}
