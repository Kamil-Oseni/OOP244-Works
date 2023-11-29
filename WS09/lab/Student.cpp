// Name: Oluwaseun Kamil Oseni                Date: 11/24/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"

namespace sdds {
	void Student::init(const char* name, int age)
	{
		if (name) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_age = age;
		}
	}

	Student::Student(const char* name, int age)
	{
		init(name, age);
	}

	Student::Student(const Student& original)
	{
		init(original.m_name, original.m_age);
	}

	Student& Student::operator=(const Student& original) 
	{
		if (this != &original) {
			delete[] m_name;
			m_name = nullptr;
			init(original.m_name, original.m_age);
		}
		return *this;
	}

	Student::~Student()
	{
		delete[] m_name;
	}

	void Student::display() const
	{
		std::cout << "Name: " << m_name << std::endl;
		std::cout << "Age: " << m_age << std::endl;
	}


}
