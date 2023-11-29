/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
Version 1.0
Author	Oluwaseun Kamil Oseni
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/15

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------

-----------------------------------------------------------*/


#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include <iostream>
#include <cstring>
#include "Menu.h"

namespace sdds {
	class AidMan {
		Menu menu1;
		char* m_filename;
		unsigned int menu();
	public:
		AidMan(const char* filename);
		~AidMan();

		AidMan(const AidMan& other) = delete;
		AidMan& operator=(const AidMan& other) = delete;

		void run();
	};


}

#endif