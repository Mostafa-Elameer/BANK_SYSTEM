#pragma once
#include <iostream>
#include "Person.h"
#include <vector>
using namespace std;

class Client:public Person
{
public  :
	double balance;
public:
	Client() {
		balance = 0;
	}
	Client(int id, string name, string password, double balance)
		:Person(id, name, password)
	{
		this->setBalance(balance);
	}
	void setBalance(double balance) {
		if (Validation::balanceValid(balance) == 1) {
			this->balance = balance;
		}
	
	}
	double getBalance() {
		return balance;
	}
    void print() {
		Person::print();
		cout << "BALANCE	 | " << getBalance() << endl;
	}
	
	// actions Cliemt 
	void deposit(double amount) {
		balance += amount;
	}
	void withDraw(double amount) {
		if (balance <= amount)return;
		else { balance -= amount; }
	}
	void transferTo(Client&c,double amount) {
		if (balance < amount)return;
		else balance -= amount ; c.deposit(amount);
	}
};

// fanction globale on a project 
static string fileClientId = "ClientLastID.txt";
static string fileClientData = "ClientsData.txt";
static vector<Client> allClients;
static vector <Client>::iterator clIt;