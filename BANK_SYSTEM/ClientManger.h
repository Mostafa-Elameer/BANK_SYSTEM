#pragma once
#include <iostream>
#include "Client.h"
#include "Validation.h"
#include "FileManger.h"
using namespace std;

class ClientManger 
{
public :
	static void ClientMenu()
	{

		system("color 2f");
		system("cls");
		cout << "  =============================\n";
		cout << "    WELCOME TO CLIENT MENU   ||\n";
		cout << "  =============================\n";
		cout << "   CHOOSE ONE OF THESE OPTIONS ?\n";
		cout << "   ( 1 ) PRINT MY INFORMITION\n";
		cout << "   ( 2 ) DEPSITE\n";
		cout << "   ( 3 ) WITHDRAW\n";
		cout << "   ( 4 ) TRANSFERTO\n";
		cout << "   ( 5 ) UPDATE MY PASSWORD\n";
		cout << "   ( 6 ) CHECE MY BALANCE\n";
		cout << "   ( 7 ) RETURN TO THE PREVIOUS PAGE\n";
		cout << "\n ENTER YOUR CHOISE ?\n";

	}
	static void back(Client* client) {
		cout << endl; 
		system("pause");
		clientOptions(client);
	}
	static Client* login(int id, string password) {
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			if (clIt->getId() == id && clIt->getPassword()==password) return clIt._Ptr;
		}
		return NULL;
	}
	static void updatePassword(Person* person) {
		person->setPassword(Validation::enterPassword());
		cout << "PASSWORD UPDATE SUCCSSUFLY\n";
	}
	static bool clientOptions(Client* client) {
		int id, choise;
		double amount;
		Employee e;
		ClientMenu();
		cin >> choise;
		switch (choise) {
		case 1: // print info
			system("cls");
			client->print();
			break;
		case 2: // deposit
			system("cls");
			client->deposit(Validation::enterBalance());
			FileManger::updateClients();
			break;
		case 3: // withdraw
			system("cls");
			cout << "HOW MUCH AMOUNT DO YOU WANT WITHDRAW ?\n";
			cin >> amount;
			client->withDraw(amount);
			cout << "AMOUNT withDraw SUCCSSFLY?\n";
			break;
		case 4: // transfer to
			cout << "ENTER ID CLIENT THAT YOU WANT TRANSFER TO\n";
			cin >> id; 
			while (e.searchClient(id) == NULL) {
				cout << "THIS ID DONT FOUND IN SYSTEM\n";
				cin >> id; 
			}
			cout << "PLEASE ENTER AMOUNT AND NAME CLIENT , DO YOU WANT TRANSFER TO HIM\n";
			cin >> amount;
			client->transferTo(*client, amount);

			break;
		case 5:// update my password 
			system("cls");
			updatePassword(client);
			FileManger::updateClients();
			break;
		case 6: // check balance 
			cout << client->getBalance();
			break;

		case 7: // return to peviuos page 
			return false;
			break;
		default:
			clientOptions(client);
			return true;
			break;
		}
		back(client);
		return true;
	}
};

