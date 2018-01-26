#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "employee.h"
using namespace std;

int main()
{
	//This code allows for 2 decimal places.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

  const int ONE = 1;
  const int TWO = 2;
  int userInput;
  string fileName;
  string emplyeeInfo;
  ifstream inputFS;

	cout << "This program has two options :" << '\n';
	cout << "1 - Create a data file, or" << '\n';
	cout << "2 - Read data from a file and print paychecks." << '\n';
	cout << "Please enter (1) to create a file or (2) to print checks :"<< endl;
	cin >> userInput;

	

	//Create employees using the defualt constructor
	Employee joe(37, 10.00, 45.00, "Joe Brown", "123 Main St.", "123-6788");
	Employee sam(21, 12.00, 30.00, "Sam Jones", "45 East State", "661-9000");
	Employee mary(15, 15.00, 40.00, "Mary Smith", "12 High Street", "401-8900");

	

//takes the information and passes it to the employee class. Will write the file.
  if(userInput == ONE)
  {
    cout << "Please enter a file name: ";
    cin >> fileName;
    cout << endl;
    ofstream outputFile;
    outputFile.open(fileName.data());
    if(!outputFile.is_open())
    {
      cout << "Could not open file." << endl;
      return 0;
    }
    
    joe.write(outputFile);
    sam.write(outputFile);
    mary.write(outputFile);
    
    cout << "Data file created ... you can now run option 2.";
    
  }
  else if(userInput == TWO)
  {
    cout << "Please enter a file name: " << endl;
    cin >> fileName;
    ifstream inputFile;
    inputFile.open(fileName.data());
    if(!inputFile.is_open())
    {
      cout << "Couldn't open file for input" << endl;
      return 0;
    }
    Employee::read(inputFile);
    joe.printCheck();
    sam.printCheck();
    mary.printCheck();
  }
  else 
  {
    cout << "Invalid input." << endl;
  }
}
