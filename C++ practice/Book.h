#ifndef _SDDS_BOOK_H
#define _SDDS_BOOK_H

#include <string>

namespace sdds {

    class Book {
    private:
        std::string auth_first_name;
        std::string auth_last_name;
        std::string email;
        int year;
        int num_of_chapters;

    public:
        Book();
        Book(std::string fname, std::string lname, int yr, int chapters);
        void display_book_info() const;

    };

}

#endif

