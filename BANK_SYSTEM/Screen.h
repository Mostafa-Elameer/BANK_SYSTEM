#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <Windows.h>
#include <thread>
#include "Person.h"
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "FileHelper.h"
#include "FileManger.h"
#include "DataSourceInterface.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManger.h"
using namespace std;
int inputId; string inputPassword;
class Screen
{
	static void bankName() {
		system("color 4f");
		cout << endl << endl << endl;
		cout << "		##       ###       ##  ######   ##       @@@@     @@@@        ###        ###      ######" << endl;
		cout << "		##      ## ##      ##  ##       ##      @@      @@    @@     ## ##      ## ##     ##    " << endl;
		cout << "		 ##     ##  ##    ##   ##       ##     @@      @@      @@   ##   ##    ##   ##    ##    " << endl;
		cout << "		  ##   ##   ##   ##    ######   ##     @@      @@      @@   ##    ##   ##    ##   ######" << endl;
		cout << "		   ## ##     ## ##     ##       ##      @@      @@    @@   ##      ## ##     ##   ##    " << endl;
		cout << "		    ##        ###      ######   ######   @@@@     @@@@     ##       ###      ##   ######" << endl;
		cout << endl << endl << endl;
		}
	static void welcome() {
		bankName();
		cout << "                @@@@@   #########  ##           #######        ###           ###      ##    ##   ##" << endl;
		cout << "               @@          ##      ##           ##   ##       ## ##         ## ##     ##    ##  ##" << endl;
		cout << "              @@           ##      ##           ##   ##      ##   ##       ##   ##    ##    ## ##" << endl;
		cout << "              @@           ##      #######      #######     #########      ##    ##   ##    #####" << endl;
		cout << "               @@          ##      ##   ##      ##   ##    ##       ##    ##      ## ##     ##   ##" << endl;
		cout << "                @@@@@   #########  #######      #######   ##         ##   ##       ###      ##    ##" << endl;

		Sleep(3000);
		system("cls");
	}
	static void close() {
		system("cls");
		system("color 4f");
		cout << "\n\n\n				THANK YOU FOR UEASD CIB BANK \n\n";
		cout << "				creat by / MOSTAFA ELAMEER \n\n";
		return;
	}
	static void loginOptions() {
		system("color 1f");
		cout << "\n\n";
		cout << "	   WELCOM TO HOME PAGE" << endl;
		cout <<	" ========================================= ?\n";
		cout << " (1) LOGIN ADMIN	(2) LOGIN EMPLOYEE\n\n";
		cout << " (3) LOGIN CLIENT	(4) EXIT\n";
		cout << " ========================================= ?\n\n";
		cout << "ENTER YOUR CHOISE ?\n";
	}
	static int  loginAs() {
		loginOptions();
		int choise;
		cin >> choise;
		if (choise == 1 || choise == 2 || choise == 3 || choise == 4) {
			return choise; 
		}
		else {
			system("cls");
			return loginAs();
		}
	}
	static void invaled(int c ) {
		system("cls");
		cout << "there is worng in id or pass \n";
		loginScren(c);
	}
	static void logout() {
		system("cls");

		loginScren(loginAs());
	}
	static void loginScren(int c) {
		int choise=c, id;
		if (choise == 4) { 
			close();
			return;
		}
		string pass; 
		system("cls");
		cout << "PLEASE ENTER ID :\n";
		cin >> id;
		cout << "PLEASE ENTER PASSWORD :\n";
		cin >> pass; 
		switch (choise){
		case 1: // admin 
			if (AdminManger::login(id, pass) != NULL) {
				while (AdminManger::AdminOptions(AdminManger::login(id, pass))!=false);
				logout();
			}
			else {
				invaled(1);
			}
			break; 
		case 2: // employee 
			if (EmployeeManager::login(id, pass) != NULL) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else {
				invaled(2);
			}
			break;
		case 3:
			if (ClientManger::login(id, pass) != NULL) {
				while (ClientManger::clientOptions(ClientManger::login(id, pass)) != false);
				logout();
			}
			else {
				invaled(3);
			}
			break;
		
		default:
			system("cls");
			loginOptions();
			break;
		}
	}

public : 
	static void RunApp(){
		FileManger::getAllData();
		welcome();
		loginScren(loginAs());
	 }
};

