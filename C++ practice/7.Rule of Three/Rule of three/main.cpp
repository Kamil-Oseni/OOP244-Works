#include<iostream>
#include "car.h"
using namespace sdds;
using namespace std;

int main() {
	
	Car car1("Tesla", 2023, 50.04, 4,"White");
	Car car2;
	Vehicle car3;
	car3 = car1;
	car3.display();
}