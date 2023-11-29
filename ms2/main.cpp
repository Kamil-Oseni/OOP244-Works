/***********************************************************************
// Final project Milestone 2
// Module: Menu and AidMan
// File: main.cpp
// Version 1.0
// Author  Oluwaseun Kamil Oseni 
// Student Id 168216216
// Description
//
// Revision History
// -----------------------------------------------------------
//Date      Reason
2023/11/15  

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

-----------------------------------------------------------*/

#include <iostream>
#include "Menu.h"
#include "AidMan.h"
#include "Utils.h"
int main() {
   std::cout << "Enter the following to test MS2:\n abc\n 0 \n 1\n 2\n 3\n 4\n 5\n 6\n 7\n 8\n 0\n--------\n";
   std::cout << "Testing Invalid Menu: " << sdds::Menu("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t").run() << std::endl;
   std::cout << "-----------------------------------------" << std::endl;
   sdds::ut.testMode();
   sdds::AidMan(nullptr).run();
   sdds::AidMan("fakeFileName.csv").run();
   return 0;
}