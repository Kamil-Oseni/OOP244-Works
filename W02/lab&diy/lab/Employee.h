//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/22/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    //I thought it would be interesting to use a class here rather than a struct, 
    // but I guess like Bart Simpson said "There's only one thing to do at a moment like this: 
    // Strut!" (Struct)

    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();

    // loads a employee structue with its values from the file
    bool load(Employee& emp);

    // allocates the dyanmic array of employees and loads all the file records into the array
    bool load();

    // displays a employee record on the screen:
    void display(const Employee& emp);

    // first sorts the employees then displays all the employees on the screen
    void display();

    //prototype for the deallocateMemory function that first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_
