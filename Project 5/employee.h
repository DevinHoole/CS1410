#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



//class declaration
class Employee
{
  private:
          int employeeNumber;
          string name;
          string address;
          string phone;
          double hourlyWage;
          double hoursWorked;
          
  public:
          Employee ();//default construtor
          Employee(int employeeNumber, double hourlyWage, double hoursWorked, string name, string address, string phone);
          //~Empoyee();
          
          //Getters
          string getName() const;
          string getAddress() const;
          string getPhone() const;
          int getEmployeeNumber() const;
          double getHourlyWage() const;
          double getHoursWorked() const;
        
          //Setters
          /*
          void setName(string name);
          void setAddress(string address);
          void setPhone(string phone);
          void setHourlyWage(double hourlyWage);
          void setHoursWorked(double hoursWorked);
          */
          
          //Functions
          double calcPay();
          void printCheck();
          
          //replaced Employee with static void
          static void read(ifstream&);
             void write(ofstream&);
          
};