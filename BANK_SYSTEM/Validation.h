#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:

	// check name valaidi
	static bool nameValid(string name) {
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i]) || name.size() < 5 || name.size() > 20) return false;
		}
		return true;
	}

	// chick password 
	static bool passValid(string password) {
		if (password.size() <8 || password.size() > 20) return false;
		else { return true; }
	}

	// chick balance 
	static bool salaryValid(double salary) {
		if (salary < 5000)return false;
		else { return true; }
	}

	//chick salary 
	static bool balanceValid(double balance) {
		if (balance < 1500) return false;
		else { return true; }
	}

	//=======================
	static string enterName() {
		string name; 
		cout << "please enter name \n";
		cin >> name; 
		while (!nameValid(name)) {
			cout << "name must be alphpit and 5 to 20 charactir\n";
			cin >> name;
		}
		return name;
	}
	static string enterPassword() {
		string password;
		cout << "EMTER NEW PASSWORD\n";
		cin >> password;
		while (!passValid(password)) {
			
			cout << "password you shoud be from 8 to 20 numper\n";
			cout << "EMTER NEW PASSWORD\n";
			cin >> password;
		}
		return password;
	}
	static double enterBalance() {
		double balance;
		cout << "HOW MUCH AMOUNT DO YOU WANT DEPOSIT ?\n";
		cin >> balance; 
		while (!balanceValid(balance)) {
			cout << "mine mum for balance 1500 \n";
			cout << "please enter balance be > 1500\n";
			cin >> balance;
		}
		return balance;
	}
};

