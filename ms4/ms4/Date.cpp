// Name: Oluwaseun Kamil Oseni                Date: 11/29/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    bool Date::validate() {
        int currentYear;
        ut.getSystemDate(&currentYear);

        status.clear();

        if (m_year < currentYear || m_year > MAXIMUM_YEAR_VALUE) {
            status = "ERR#1: Invalid year in date";
            return false;
        }

        if (m_month < 1 || m_month > 12) {
            status = "ERR#2: Invalid month in date";
            return false;
        }

        int daysInMonth = ut.daysOfMon(m_month, m_year);
        if (m_day < 1 || m_day > daysInMonth) {
            status = "ERR#3: Invalid day in date";
            return false;
        }

        if (invalid) {
            status = "Invalid date value";
            return false;
        }

        return true;
    }


    const Status& Date::state()
    {
        return status;
    }
    int Date::uniqueDateValue() const
    {
        return m_year * 372 + m_month * 31 + m_day;
    }
    Date::Date()
    {
        invalid = false;
        m_format = true;
        ut.getSystemDate(&m_year, &m_month, &m_day);
    }
    Date::operator bool() const {
        return status;
    }
    Date::Date(int year, int month, int day)
    {
        invalid = false;
        m_format = true;
        m_year = year;
        m_month = month;
        m_day = day;
        validate();

    }


    Date& Date::formatted(bool slash)
    {
        if (slash == false)
        {
            m_format = false;
        }


        return *this;
    }

    bool Date::operator==(const Date& right) const
    {
        return this->uniqueDateValue() == right.uniqueDateValue();
    }
    bool Date::operator!=(const Date& right) const
    {
        return this->uniqueDateValue() != right.uniqueDateValue();
    }
    bool Date::operator>=(const Date& right) const
    {
        return this->uniqueDateValue() >= right.uniqueDateValue();
    }
    bool Date::operator<=(const Date& right) const
    {
        return this->uniqueDateValue() <= right.uniqueDateValue();
    }
    bool Date::operator<(const Date& right) const
    {
        return this->uniqueDateValue() < right.uniqueDateValue();
    }
    bool Date::operator>(const Date& right) const
    {
        return this->uniqueDateValue() > right.uniqueDateValue();
    }
    bool notint(bool chara)
    {
        return chara == true;
    }

    std::istream& Date::read(std::istream& istr)
    {
        int number;
        int day1;
        int day2;
        int mon1;
        int mon2;
        int year1;
        int year2;
        istr >> number;
        if (istr)
        {
            if (number <= 9999)
            {
                day2 = number % 10;
                day1 = number / 10 % 10;
                mon2 = number / 100 % 10;
                mon1 = number / 1000 % 10;
                if (mon1 == 0)
                {
                    m_month = mon2;
                }
                else
                {
                    m_month = (mon1 * 10) + mon2;
                }
                if (day1 == 0)
                {
                    m_day = day2;
                }
                else
                {
                    m_day = (day1 * 10) + day2;
                }
                ut.getSystemDate(&m_year);
            }
            else if (number >= 100000 && number <= 999999)
            {
                day2 = number % 10;
                day1 = number / 10 % 10;
                mon2 = number / 100 % 10;
                mon1 = number / 1000 % 10;
                year2 = number / 10000 % 10;
                year1 = number / 100000 % 10;

                if (year1 == 0)
                {
                    m_year = 2000 + year2;
                }
                else
                {
                    m_year = 2000 + ((year1 * 10) + year2);
                }
                if (mon1 == 0)
                {
                    m_month = mon2;
                }
                else
                {
                    m_month = (mon1 * 10) + mon2;
                }
                if (day1 == 0)
                {
                    m_day = day2;
                }
                else
                {
                    m_day = (day1 * 10) + day2;
                }
            }

        }
        else
        {
            invalid = true;
        }





        if (!validate())
        {

            istr.setstate(ios::badbit);
        }
        return istr;

    }
    std::ostream& Date::write(std::ostream& os) const
    {




        if (m_format == true)
        {
            os << m_year;
            os << '/';
            os.fill('0');
            os.width(2);
            os << m_month;
            os << '/';
            os.width(2);
            os << m_day;
            os.fill(' ');
        }
        else if (m_format == false)
        {
            int year = m_year - 2000;
            os << year;
            os.fill('0');
            os.width(2);
            os << m_month;
            os.width(2);
            os << m_day;
            os.fill(' ');
        }


        return os;
    }
    std::ostream& operator<<(std::ostream& os, const Date& dat)
    {
        return dat.write(os);
    }
    std::istream& operator>>(std::istream& is, Date& dat)
    {
        return dat.read(is);
    }
}