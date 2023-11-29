// Name: Oluwaseun Kamil Oseni                Date: 11/24/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {

	class Student
	{
	private:
		char* m_name{};
		int m_age{};
	public:
		void init(const char* name, int age);
				
		Student() = default;
		Student(const char* name, int age);

		Student(const Student& original);
		Student& operator=(const Student& original);
		virtual ~Student();

		void display()const;

	};
	

}


#endif // !SDDS_STUDENT_H
