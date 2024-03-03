#pragma once
#include <iostream>
#include "EmployeeManager.h"
using namespace std;
class AdminManger
{

public:
	void static AdminMune(){
		system("cls");
	cout << "  =============================\n";
	cout << "  ||  WELCOME TO Admin MENU   ||\n";
	cout << "  =============================\n";
	cout << "   CHOOSE ONE OF THESE OPTIONS ?\n";
	cout << "   ( 1 ) PRINT MY INFORMITION\n";
	cout << "   ( 2 ) UPDATE MY PASSWORD\n";
	cout << "   ( 3 ) ADD NEW CLIENT\n";
	cout << "   ( 4 ) SEARCH FOR CLIENT\n";
	cout << "   ( 5 ) LIST ALL CLIENT\n";
	cout << "   ( 6 ) EDIT CHECE \n";
	cout << "   ( 7 ) ADD NEW Employee\n";
	cout << "   ( 8 ) SEARCH FOR CLIENT \n";
	cout << "   ( 9 ) LIST ALL employee\n";
	cout << "   ( 10 ) EDIT empolyee\n";
	cout << "   ( 11 ) RETURN TO THE PREVIOUS PAGE\n";
	cout << "\n ENTER YOUR CHOISE ?\n";
	}

	static void back(Admin* admin) {
		//system("cls");
		//system("pause");
		AdminOptions(admin);
	}

	static Admin* login(int id, string password) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id || aIt->getPassword() == password) return aIt._Ptr;
		}
		return NULL;

	}

	static bool AdminOptions(Admin* admin) {
		AdminMune();
		Employee e;
		int choise, id;
		cin >> choise;
		switch (choise){
		case 1 : // info 
			system("cls");
			admin->print();
			system("pause");

			break; 
		case 2://update pass
			system("cls");
			ClientManger::updatePassword(admin);
			FileManger::updateAdmin();
			system("pause");

			break;
		case 3: // add client 
			system("cls");
			EmployeeManager::newClientt(admin);
			system("pause");
			break;
			
		case 4: // SEARCH client
			system("cls");
			EmployeeManager::searchForClient(admin);
			system("pause");

			break;
		case 5: // list clients
			system("cls");
			EmployeeManager::listclients(admin);
			system("pause");

			break;
		case 6: // edit 
			system("cls");
			EmployeeManager::editClient(admin);
			FileManger::updateClients();
			system("pause");

			break;
		case 7: // add employee
			system("cls");
			e.setName(Validation::enterName());
			e.setPassword(Validation::enterPassword());
			e.setSalary(Validation::enterBalance());
			e.setId(FileHelper::getLast(fileEmployeeId) + 1);
			admin->addEmployee(e);
			FileManger::updateEmployees();
			system("pause");

			break;
		case 8: // print info empl
			system("cls");
			cout << "EMTER ID EMPLOYEE THAT YOU WANT SEARCH\n";
			cin >> id; 
			if (admin->searchEmployee(id) == NULL) {
				cout << "EMPLOYEE NOT FOUND IN SYSTEM\n"; 
			}
			else {
				admin->searchEmployee(id)->print();
			}
			system("pause");
			break;
		case 9: // list all empl
			system("cls");
			admin->listEmployees();
			system("pause");

			break;
		case 10: // edit 
			cout << "EMTER ID EMPLOYEE THAT YOU WANT EDIT\n"; 
			cin >> id; 
			if (admin->searchEmployee(id) == NULL) {
				cout << "EMPLOYEE NOT FOUND IN SYSTEM\n"; 
			}
			else {
				string name = Validation::enterName();
				string password = Validation::enterPassword();
				double salary = Validation::enterBalance();
				admin->editEmployee(id , name , password, salary);
				FileManger::updateEmployees();
				system("pause");

			}
			break;
		case 11:
			return false;
			break; 
		default:
			system("cls");
			AdminOptions(admin);
			return true;
			break;
		}
		back(admin);
		return true;
	}
};

