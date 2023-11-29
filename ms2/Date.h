/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.h
Version 1.0
Author	Oluwaseun Kamil Oseni
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/05  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

-----------------------------------------------------------*/



#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include<cstring>
#include<sstream>
#include"Status.h"
namespace sdds {

    const int MAXIMUM_YEAR_VALUE = 2030;



    class Date
    {
        Status status;
        int m_year;
        int m_month;
        int m_day;
        bool m_format;
        bool invalid;
        
        bool validate();
        int uniqueDateValue() const;

    public:
        Date();
        Date(int year, int month, int day);

        bool notint(bool chara = false);
        operator bool() const;
        const Status& state();
        Date& formatted(bool slash);

        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator>=(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;

        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& os, const Date& dat);
    std::istream& operator>>(std::istream& is, Date& dat);
}
#endif