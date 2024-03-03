#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include "Employee.h"
#include "Client.h"
#include "Admin.h"
using namespace std;

class Parser
{
private : 
	static vector<string> split(string line) {
		vector <string> cut;
		string word;
		stringstream ss(line);
		while (getline(ss,word,'|')) {
			cut.push_back(word);
		}
		return cut;
	}

public :
	static Client ParserToClinet(string line) {
		Client c;
		vector<string> saveSplit = split(line);
		c.setId(stoi(saveSplit[0]));
		c.setName(saveSplit[1]);
		c.setPassword(saveSplit[2]);
		c.setBalance(stod(saveSplit[3]));
		return c;
	}
	static Employee parserToEmployee(string line) {
		Employee e;
		vector <string > saveSplit = split(line);
		e.setId(stoi(saveSplit[0]));
		e.setName(saveSplit[1]);
		e.setPassword(saveSplit[2]);
		e.setSalary(stod(saveSplit[3]));
		return e;
	}
	static Admin parserToAdmin(string line) {
		Admin a;
		vector <string> savesplit = split(line);
		a.setId(stoi(savesplit[0]));
		a.setName(savesplit[1]);
		a.setPassword(savesplit[2]);
		a.setSalary(stod(savesplit[3]));
		return a;
	}

};


