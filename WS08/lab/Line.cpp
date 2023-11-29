// Name: Oluwaseun Kamil Oseni                Date: 11/17/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line() : LblShape() {
		m_length = 0;
	};

	Line::Line(const char* Cstring, const int length) : LblShape(Cstring) {
		m_length = length;
	};

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore();
	};

	void Line::draw(std::ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;

			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	};
}