#pragma once
#include <iostream>	
#include "Validation.h"
using namespace std ; 
class Person  
{
protected:
	string name, password;
	int id;
public:

	// constractur 
	Person() {
		this->name = " ";
		this->password = " ";
		this->id = 0;
	}
	Person(int id, string name, string password) {
		this->setId(id);
		this->setName(name);
		this->setPassword(password);
	}

	// seter
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (Validation::nameValid(name) == 1)
			this->name = name;
	}
	void setPassword(string password) {
		if (Validation::passValid(password) == 1)
		{
			this->password = password;
		}
	}
	
	// geter 
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}

	// print 
	void print() {
		cout << "=========================================\n";
		cout << "ID	 | " << getId() << endl;
		cout << "NAME	 | " << getName() << endl;
		cout << "PASSWORD | " << getPassword() << endl;
	}
};

