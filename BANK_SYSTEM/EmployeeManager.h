#pragma once
#include <iostream>
#include "Employee.h"
#include <vector>
#include "ClientManger.h"
#include "Client.h"
#include "FileHelper.h"
using namespace std; 
class EmployeeManager
{
public :
	static void employeeMune() {
		system("cls");
		system("color 1f");

		cout << "  =============================\n";
		cout << "  ||  WELCOME TO employee MENU ||\n";
		cout << "  =============================\n";
		cout << "   CHOOSE ONE OF THESE OPTIONS ?\n";
		cout << "   ( 1 ) PRINT MY INFORMITION\n";
		cout << "   ( 2 ) UPDATE MY PASSWORD\n";
		cout << "   ( 3 ) ADD NEW CLIENT\n";
		cout << "   ( 4 ) SEARCH FOR CLIENT\n";
		cout << "   ( 5 ) LIST ALL CLIENT\n";
		cout << "   ( 6 ) EDIT CHECE \n";
		cout << "   ( 7 ) RETURN TO THE PREVIOUS PAGE\n";
		cout << "\n ENTER YOUR CHOISE ?\n";

	}
	static void muneUpdate() {
		cout << "(1): update name\n";
		cout << "(2): update password\n";
		cout << "(3): update balance\n";
		cout << "(4): exit\n";
		cout << "ENTER YOUR CHOISE :\n";
	}

	static void back(Employee* employee) {
		system("pause");
		employeeOptions(employee);
	}

	static void newClientt(Employee* employee) {
		Client client; 
		client.setId(FileHelper::getLast(fileClientId) + 1);
		string name;
		client.setName(Validation::enterName());
		client.setPassword(Validation::enterPassword());
		employee->addClient(client);
		FileManger::updateClients();
	}

	static void searchForClient(Employee* employee) {
		int id;
		cout << "EMTER ID CLIENT THAT YOU WANT SEARCH \n";
		cin >> id;
		if (employee->searchClient(id) == NULL) {
			cout << "CLIENT NOT FOUND IN SYSTEM\n";
		}
		else {
			employee->searchClient(id)->print();
		}
	}

	static void listclients(Employee* employee) {
		system("cls");
		employee->listClient();
	}

	static void editClient(Employee* employee) {
		int id; 
		cout << "ENTER ID CLIENT YOU WANT SEARCH\n";
		cin >> id; 
		if (employee->searchClient(id) == NULL) {
			cout << "CLIENT NOT FOUND IN SYSTEM\n"; 
		}

		string name = Validation::enterName();
		string password = Validation::enterPassword();
		double balance = Validation::enterBalance();
		employee->editeClient(id, name, password, balance);
		FileManger::updateClients();

	}

	static Employee* login(int id, string password) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id || eIt->getPassword() == password) return eIt._Ptr;
		}
		return NULL; 
	}

	static bool employeeOptions(Employee* employee) {
		employeeMune();
		int choise; 
		cin >> choise; 
		switch (choise) {
		case 1: // PRINT info 
			system("cls");
			employee->print();
			break; 
		case 2: // update pass 
			system("cls");
			ClientManger::updatePassword(employee);
			FileManger::updateEmployees();
			break;
		case 3: // add client 
			system("cls");
			newClientt(employee);
			break;
		case 4:// search  
			system("cls");
			searchForClient(employee);
			break;
		case 5:// list client 
			system("cls");
			listclients(employee);
			break;
		case 6: // edit
			system("cls");
			editClient(employee);
			break;
		case 7 :
			return false; 
			break;
		default :
			system("cls");
			employeeOptions(employee);
			return true;
			break; 
		}
		back(employee);
		return true;
	}
};

