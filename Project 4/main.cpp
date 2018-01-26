#include <iostream>
#include <vector>
#include "employee.h"
using namespace std;

int main()
{
	//This code allows for 2 decimal places.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//Create employee1 using the defualt constructor
	Employee employee1(37, 10.00, 45.00, "Joe Brown", "123 Main St.", "123-6788");
	//Create employee2 using the parameterized constructor
	Employee employee2(37, 12.50, 30.00, "Sam Jones", "45 East State", "661-9000");

	//Call to Print out the information for employee #1
	employee1.printCheck();

	// ***************************************************************************************

	//Call to Print out the information for employee #2
	employee2.printCheck();
}
