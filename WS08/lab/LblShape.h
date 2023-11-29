// Name: Oluwaseun Kamil Oseni                Date: 11/17/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LBL_SHAPE_H
#define SDDS_LBL_SHAPE_H

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
	private:
		char* m_label = nullptr;

	protected:
		const char* label() const;

	public:
		LblShape();
		LblShape(const char* Cstring);
		
		~LblShape();

		LblShape(const LblShape& cpy) = delete;
		LblShape& operator=(const LblShape& cpy) = delete;

		void getSpecs(std::istream& is);
	};
}
#endif // !SDDS_LBL_SHAPE_H