/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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

#include <iostream>
#include <cstring>
#include <string>
#include "Menu.h"


using namespace std;

namespace sdds {
		
	Menu::Menu(const char* content)
	{
		if (m_numOfOptions > MAX_OPTIONS_NUM || content == nullptr) {
			m_content = nullptr;
			m_numOfOptions = 0;
		}
		else {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);

			m_numOfOptions = 0;

			for (int i = 0; content[i] != '\0'; i++) {
				if (content[i] == '\t') {
					m_numOfOptions++;
				}
			}
			m_numOfOptions++;
		}
	}

	Menu::~Menu()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	unsigned int Menu::run() const
	{
		unsigned int value = 0;
		bool valid = false;

		if (m_content == nullptr || m_numOfOptions > MAX_OPTIONS_NUM) {
			cout << "Invalid Menu!" << endl;
			return 0;
		}

		const char* currentItem = m_content;

		for (int i = 0; i < m_numOfOptions; i++) {
			const char* nextItem = strchr(currentItem, '\t');

			if (nextItem == nullptr) { // this is for the last item without the delimiter \t
				cout << i + 1 << "- " << currentItem << endl;
				break;
			}

			cout << i + 1 << "- " << string(currentItem, nextItem - currentItem) << endl;
			currentItem = nextItem + 1;
		}

		cout << "---------------------------------" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";

		while (!valid) {
			cin >> value;
			if (!cin >> value || value < 0 || (signed int)value > m_numOfOptions)
			{ 

				if (value < 0 || (signed int)value > m_numOfOptions) {
					cout << "Value out of range [0<=val<=" << m_numOfOptions << "]: ";
				}

				else {
					cout << "Invalid Integer, retry: ";
				}
				cin.clear();
				cin.ignore(100, '\n');
			}

			else {
				valid = true;
			}
		}

		return value;
	}
	int Menu::getOptions() {
		return m_numOfOptions;
	}

	const char* Menu::getContent() {
		return m_content;
	}
}
