#pragma once
#include <iostream>
#include <string>
#include "FileHelper.h"
#include "DataSourceInterface.h"
using namespace std; 

class FileManger :public DataSourceInterface
{
public:
	static void addClient(Client c) {
		FileHelper::saveClient(c);
	}
	static void addEmployee(Employee e) {
		FileHelper::saveEmployee(fileEmployeeData, fileEmployeeId ,e);
	}
	static void addAdmin(Admin a) {
		FileHelper::saveEmployee(fileAdminData, fileAdminId ,a);
	}
	static void getAllClients() {
		FileHelper::getClients();
	}
	static void getAllEmployees() {
		FileHelper::getEmployees();
	}
	static void getAllAdmins() {
		FileHelper::getAdmins();
	}
	static void removeAllClients() {
		FileHelper::clearFile(fileClientData ,fileClientId);
	}
	static void removeAllEmployees() {
		FileHelper::clearFile(fileEmployeeData, fileEmployeeId);
	}
	static void removeAllAdmins() {
		FileHelper::clearFile(fileAdminData,fileAdminId);
	}

	//========================
	// creat by eng\ ahmed amin @ he siad,we will need to that in phase 3
	
	static void getAllData() {
		getAllClients();
		getAllAdmins();
		getAllEmployees();
	}

	// i uesd iterator for all mempers . when i can ubdate data in vector 

	static void updateClients() {
		removeAllClients();
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++)
			addClient(*clIt);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++)
			addEmployee(*eIt);
	}
	static void updateAdmin() {
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++)
			addAdmin(*aIt);
	}


};

 