// Name: Oluwaseun Kamil Oseni                Date: 11/17/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Rectangle.h"
#include "Line.h"

using namespace std;

namespace sdds
{
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	};

	Rectangle::Rectangle(const char* Cstring, const int width, const int height) : LblShape(Cstring)
	{
		int value = strlen(label()) + 2;

		if (height < 3 || width < value) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	};

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(2000, ',');
		is >> m_height;
		is.ignore(2000, '\n');
	};

	void Rectangle::draw(std::ostream& os) const
	{
		if (m_width > 0 && m_height > 0) {
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;

			os << "|";
			os << setw((streamsize)m_width - 2) << setfill(' ') << left << label();
			os << "|" << endl;

			for (int i = 0; i < m_height - 3; i++) {
				os << "|" << setw((streamsize)m_width - 2) << " " << "|" << endl;
			}

			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+";
		}
	};
}