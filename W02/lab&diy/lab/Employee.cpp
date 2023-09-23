//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/22/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds {
    // Holds the number of records (employees) in the file.
    // Should be used (after setting) to allocate the dynamic array of Employees.
    int noOfEmployees;

    // Holds the address of the dynamically-allocated array of employees.
    // The size of the array is "noOfEmployees".
    Employee* employees;

    // Sorting function for employees based on employee number
    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // loads from the file the information about the employee and returns true if it was successful (false otherwise).
    bool load(Employee& emp) {
        bool ok = true;
        emp.m_name = nullptr;
        if (read(emp.m_empNo) && read(emp.m_salary) && read(emp.m_name)) {
            ok = true;
        }
        else {
            if (emp.m_name) {
                delete[] emp.m_name;
                emp.m_name = nullptr;
            }
            ok = false;
        }
        return ok;
    }

    // Dynamically allocate memory for an array of Employees and read all the records of the file into the dynamic array's elements
    bool load() {
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (int i = 0; i < noOfEmployees; i++) {
                if (!load(employees[i])) {
                    cerr << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    deallocateMemory();
                    return false;
                }
            }
            closeFile();
            return true;
        }
        else {
            cerr << "Could not open data file: " << DATAFILE << endl;
            return false;
        }
    }

    // Displays an Employee's data
    void display(const Employee& emp) {
           
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }

    // Displays all Employee records, sorted by employee number
    void display() {
        sort();
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    // Deallocates memory used for employee records
    void deallocateMemory() {
        for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
    }
}
