
/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include "AidMan.h"
#include "Date.h"

 using namespace std;
namespace sdds {
	unsigned int AidMan::menu()
	{
		Date date;

		cout << "Aid Management System" << endl;
		cout << "Date: " << date << endl;
		if (m_filename) {
			cout << "Data file: " << m_filename << '\n' << endl;
		}
		else {
			cout << "Data file: No file\n" << endl;
		}

		return menu1.run();
	}
	AidMan::AidMan(const char* filename) :menu1("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database")
	{
		if (filename != nullptr) {
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
		}
		else {
			m_filename = nullptr;
		}
	}
	AidMan::~AidMan()
	{
		delete[] m_filename;
		m_filename = nullptr;
	}

	void AidMan::run()
	{

		string menuoptions[MAX_OPTIONS_NUM];
		bool valid = false;
		int Options = menu1.getOptions();
		const char* content = menu1.getContent();

		while (!valid) {
			unsigned int input = menu();

			if (input == 0) {
				cout << "Exiting Program!" << endl;
				break;
			}

			for (int i = 0; i < Options; i++) {

				if (!menuoptions[i].empty()) {
					break;
				}
				const char* nextItem = strchr(content, '\t');;

				if (nextItem)
				{
					menuoptions[i] = string(content, nextItem - content);
					content = nextItem + 1;
				}
				else 
				{
					menuoptions[i] = content;
				}
			}

			cout << "\n****" << menuoptions[input - 1] << "****\n" << endl;
		}















	}

}