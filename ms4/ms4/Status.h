// Name: Oluwaseun Kamil Oseni                Date: 11/29/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <ostream>

namespace sdds {
    class Status {
    public:
        Status();
        Status(const char* desc);
        Status(int c);
        Status(const Status& other);
        Status& operator=(const Status& other);
        Status& operator=(const char* desc);
        Status& operator=(int c);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        friend std::ostream& operator<<(std::ostream& os, const Status& status);
        // virtual bool isClear() const;
        ~Status();

    private:
        char* description;
        int code;
    };
}



#endif