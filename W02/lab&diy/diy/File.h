//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/25/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
    bool openFile(const char filename[]);
    void closeFile();
    int noOfRecords();
    bool read(char*& name);
    bool read(int& empNo);
    bool read(double& salary);
    
}

#endif // !SDDS_FILE_H_
