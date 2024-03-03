#pragma once
#include <iostream> 
#include "Person.h"
#include <fstream>
#include "Client.h"
#include <iterator>
#include <vector>

using namespace std;

class Employee :public Person{
protected:
	double salary;
public:

	Employee() {
		this ->salary = 0;
	}
	Employee(int id, string name, string password, double salary)
		:Person(id, name, password)
	{
		setSalary(salary);
	}


	virtual void setSalary(double salary) {
		if (Validation::salaryValid(salary) == 1)
		{
			this->salary = salary;
		}
	}
	double getSalary() {
		return salary;
	}

	// print test 
	void print() {
		Person::print();
		cout << "SALARY	 | " << getSalary() << endl;
	}
	
	// actions doing employee 
	void addClient(Client& client) {
		allClients.push_back(client);
	}

	static Client*searchClient(int id) {
		for (clIt = allClients.begin();clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id) return clIt._Ptr; 
		}
		return NULL;
	}
	void listClient() {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			clIt->print();
			cout << "========================\n";
		}
	}

	void editeClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}

};

// fanction globale on a project 
static string fileEmployeeData = "EmployeesData.txt";
static string fileEmployeeId = "EmployeeLastID.txt";
static vector <Employee> allEmployees;
static vector <Employee>::iterator eIt;



