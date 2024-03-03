#pragma once
#include <iostream> 
#include <string>
#include "Employee.h"
using namespace std;

class Admin :public Employee
{
protected :
	double salary;
public:
	Admin() {
		salary = 0;
	}
	Admin(int id, string name, string password, double salary)
		:Employee(id, name, password ,salary) {
	}
	void print() {
		Person::print();
		cout << "SALARY	 | " << getSalary() << endl;
	}

	// fanction doing an admin  
	void addEmployee(Employee e) {
		allEmployees.push_back(e);
	}
	Employee * searchEmployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id) return eIt._Ptr;
		}
		return NULL;
	}
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}
	void listEmployees() {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			eIt->print();
			cout << "=====================\n";
		}
	}

};

// fanction globle on a project 
static string fileAdminId = "AdminLastID.txt";
static string fileAdminData = "AdminsData.txt";
static vector <Admin> allAdmins;
static vector<Admin>::iterator aIt;


