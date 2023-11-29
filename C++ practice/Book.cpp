
#include <iostream>
#include "Book.h"


namespace sdds {
    Book::Book() {
        auth_first_name = "none";
        auth_last_name = "none";
        year = 0;
        num_of_chapters = 0;
        email = "none";
    }

    Book::Book(std::string fname, std::string lname, int yr, int chapters) {
        auth_first_name = fname;
        auth_last_name = lname;
        year = yr;
        num_of_chapters = chapters;
        email = fname + "." + lname + "@gmail.com";
    }

    void Book::display_book_info() const {
        std::cout << "Author's name is " << auth_first_name << " " << auth_last_name << std::endl;
        std::cout << "Author's email is " << email << std::endl;
        std::cout << "Book was published in " << year << " and it has " << num_of_chapters << " chapters" << std::endl;
    }

    
}
