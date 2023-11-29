// Name: Oluwaseun Kamil Oseni                Date: 11/17/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
	private:
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char* Cstring, const int width, const int height);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif // !SDDS_RECTANGLE_H