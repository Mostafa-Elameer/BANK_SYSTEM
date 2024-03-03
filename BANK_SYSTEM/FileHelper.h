#pragma once
#include <iostream>
#include <string> 
#include <sstream>
#include <fstream>
#include "Parser.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std; 

class FileHelper
{
public:
	static void saveLast(string fileName, int id) {
		fstream myFile;
		myFile.open(fileName, ios::out);
		myFile << ++id;
		myFile.close();
	}
	static int getLast(string fileName) {
		fstream myFile;
		int lastId;
		myFile.open(fileName, ios::in);
		myFile >> lastId;
		myFile.close();
		return lastId;
	}
	
	static void saveClient(Client c) {
		fstream myFile;
		int lastID = getLast(fileClientId); 
		lastID++;
		myFile.open("ClientsData.txt", ios::app);
		c.setId(lastID);
		myFile << c.getId() << "|";
		myFile << c.getName() << "|";
		myFile << c.getPassword() << "|";
		myFile << c.getBalance() << endl;
		myFile.close();
		saveLast(fileClientId, getLast(fileClientId));
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		fstream myFile;
		int employeeId = getLast(lastIdFile);
		employeeId++;
		// don't need this condition
		if (fileName == fileEmployeeData && lastIdFile == fileEmployeeId || fileName == fileAdminData && lastIdFile == fileAdminId) {
		myFile.open(fileName, ios::app);
		e.setId(employeeId);
		myFile << e.getId() << "|";
		myFile << e.getName() << "|";
		myFile << e.getPassword() << "|";
		myFile << e.getSalary() << endl;
		myFile.close();
		saveLast(lastIdFile, getLast(lastIdFile));
		}
	}

	// fanction get .work on coming data from file ,then count data in vector  
	// This vetctor MUST be Global in Client File!!!!! == doun 
	static void getClients() {	
		fstream file;string line;
		file.open(fileClientData ,ios::in);
		while (getline(file, line)) {
			Client c =Parser::ParserToClinet(line);
			allClients.push_back(c);
		}
		file.close();
	}
	static void getEmployees() {

		string line; fstream file;
		file.open(fileEmployeeData, ios::in);
		while (getline(file, line)) {
			Employee e = Parser::parserToEmployee(line); 
			allEmployees.push_back(e); 
		}
		file.close();

	}
	static void getAdmins() {
		string line ; fstream file;

		file.open(fileAdminData, ios::in);
		while (getline(file,line)) {
			allAdmins.push_back(Parser::parserToAdmin(line));
		}
		file.close();
	}

	// this clear any file when i uesd 
	static void clearFile(string fileName, string lastIdFile) {
		fstream file;
		if (fileName == fileClientData || fileName == fileEmployeeData || fileName == fileAdminData) {
			file.open(fileName, ios::out);
			// file << ""; // remove
			file.close();
			file.open(lastIdFile, ios::out);
			file << 0;
			file.close();
		}
	}

};

