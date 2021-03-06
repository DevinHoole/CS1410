#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "employee.h"

//Default Constructor
Employee::Employee()
{
	this->name = "";
	this->address = "";
	this->phone = "";
	this->employeeNumber = 0;
	this->hourlyWage = 0;
	this->hoursWorked = 0;
}
//Parameterized Constructor
Employee::Employee(int employeeNumber, double hourlyWage, double hoursWorked, string name, string address, string phone)
{
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->employeeNumber = employeeNumber;
	this->hourlyWage = hourlyWage;
	this->hoursWorked = hoursWorked;
}

//Destructor
/*
Employee::~Employee()
{

}
*/

//Getters code
string Employee::getName()
const {
	return name;
}
string Employee::getAddress()
const {
	return address;
}
string Employee::getPhone()
const {
	return phone;
}
int Employee::getEmployeeNumber()
const {
	return employeeNumber;
}
double Employee::getHourlyWage()
const {
	return hourlyWage;
}
double Employee::getHoursWorked()
const {
	return hoursWorked;
}

//Setters code
/*
void setName(string name)
{
this->name = name;
}
void setAddress(string address)
{
this-> address = address;
}
void setPhone(string phone)
{
this-> phone = phone;
}
void setHourlyWage(double hourlyWage)
{
this-> hourlyWage = hourlyWage;
}
void setHoursWorked(double hoursWorked)
{
this-> hoursWorked = hoursWorked;
}
*/
//Functions code
double Employee::calcPay()
{
	double netPay = 0; //amount one receives after taxes 
	double grossPay = 0; //money you've made while working at your job, figured before any deductions are taken
	double overtimeHours = 0;
	double overtimeTotal = 0;
	double overtime = 1.5; //Multiply your standard rate by 1.5 
	double federalTax = .2;
	double stateTax = .075;
	int fullTimeHours = 40;//how many hours required to work to be full time.


	if (hoursWorked > fullTimeHours)
	{
		overtimeHours = (hoursWorked - fullTimeHours);//hours of overtime that were worked.
		overtimeTotal = overtimeHours * (hourlyWage * overtime);//How much they get paid for working overtime
																//finding your gross pay before deductions
		grossPay = fullTimeHours * hourlyWage + overtimeTotal;
		//finding take home pay after deductions
		netPay = grossPay - (federalTax * grossPay) - (stateTax * grossPay);

		return netPay;
	}
	else
	{
		//finding your gross pay before deductions
		grossPay = hoursWorked * hourlyWage;
		//finding take home pay after deductions
		netPay = grossPay - (federalTax * grossPay) - (stateTax * grossPay);
		return netPay;
	}

}

void Employee::printCheck()
{
	cout << "Employee Name: " << getName() << endl;
	cout << "Employee Number: " << getEmployeeNumber() << endl;
	cout << "Address: " << getAddress() << endl;
	cout << "Phone: " << getPhone() << endl;
	cout << endl;
	cout << "....................UVU Computer Science Dept................................." << endl;
	cout << endl;
	cout << "Pay to the order of " << getName() << "....................................$" << calcPay() << endl;
	cout << endl;
	cout << endl;
	cout << "United Community Credit Union" << endl;
	cout << ".............................................................................." << endl;
	cout << endl;
	cout << "Hours worked: " << getHoursWorked() << endl;
	cout << "Hourly wage: " << getHourlyWage() << endl;
	cout << endl;
	cout << endl;
}

/*Employee Employee::read(ifstream & inputStream)
{
	Employee e;
	string input;

	/*if (!getline(inputStream, input))
				throw runtime_error("error reading length");
	r.setLength(stoi(input)); 

	if (!getline(inputStream, input))
				throw runtime_error("error reading width"); 
	r.setWidth(stoi(input)); 
	
	return e;
}

void Employee::write(ofstream & outputStream)
{
	//outputStream << printCheck << '\n';
	
}
*/