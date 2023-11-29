// Name: Oluwaseun Kamil Oseni                Date: 11/17/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "LblShape.h"
#include "Shape.h"

using namespace std;
namespace sdds
{
	LblShape::LblShape() {
		if (this->m_label != nullptr) {
			m_label = nullptr;
		}
	};

	LblShape::LblShape(const char* Cstring) {

		delete[] this->m_label;
		this->m_label = new char[strlen(Cstring) + 1];
		strcpy(this->m_label, Cstring);
	};

	const char* LblShape::label() const {
		return m_label;
	};

	void LblShape::getSpecs(std::istream& is) {
		char Cstring[100];

		is.get(Cstring, 100, ',');
		is.ignore();

		delete[] this->m_label;
		m_label = new char[strlen(Cstring) + 1];
		strcpy(m_label, Cstring);
	};

	LblShape::~LblShape() {
		delete[] m_label;
	};
}