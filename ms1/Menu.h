/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#define MAX_OPTIONS_NUM 15
#include <iostream>
#include<cstring>

	namespace sdds {

		class Menu {
			char* m_content;
			int m_numOfOptions;

		public:
			Menu(const char* content = nullptr);
			Menu(const Menu& other) = delete;
			Menu& operator=(const Menu& other) = delete;
			~Menu();

			unsigned int run() const;
			int getOptions();
			
			const char* getContent();
		};



	}

#endif