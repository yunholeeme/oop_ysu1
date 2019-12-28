// oop_ysu1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int NAME_LEN = 20;

typedef struct _Account
{
	int id;
	int balance;
	char name[NAME_LEN];
} Account;

Account pArray[100];
int index = 0;

void printMenu();
void openAnAccount();
void deposit();
void withdraw();
void Inquire();

enum
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT,
};

int main()
{
	int choice = 0;
	int flag;

	while (1)
	{
		printMenu();
		cout << "select a number : " << endl;
		while ((flag = scanf("%d", &choice)) != 1)
		{
			cout << "Wrong Input. try again.\n" << endl;
			exit(EXIT_FAILURE);
		}

		switch (choice)
		{
		case MAKE:
			openAnAccount();
			break;
		case DEPOSIT:
			deposit();
			break;
		case WITHDRAW:
			withdraw();
			break;
		case INQUIRE:
			Inquire();
			break;
		case EXIT:
			return 0;
		default:
			cout << " please choice 1~4" << endl;
			break;
		}
	}
	return 0;
}

void printMenu()
{
	cout << "=== Open an account ===" << endl;
	cout << "1. Open an Account" << endl;
	cout << "2. Deposit\t" << endl;
	cout << "3. Withdraw\t" << endl;
	cout << "4. Inquire\t" << endl;
	
}

void openAnAccount()
{
	int id;
	int balance;
	char name[NAME_LEN];
	cout << "Input accout id : ";
	cin >> id;
	cout << "Input name : ";
	cin >> name;
	cout << "Input money : ";
	cin >> balance;
	strcpy(pArray[index].name, name);
	pArray[index].id = id;
	pArray[index].balance = balance;
	index++;
}
void deposit()
{
	int id;
	int money;
	//char name[NAME_LEN];
	cout << "Input account id : ";
	cin >> id;
	cout << "Input deposit money : ";
	cin >> money;
	for (int i = 0; i < index; ++i)
	{
		if (id == pArray[i].id)
		{
			pArray[i].balance += money;
			cout << "deposit completed" << endl;
			return;
		}
	}
	cout << id << " is not a valid id." << endl;
}
void withdraw()
{
	int id;
	int money;
	//char name[NAME_LEN];
	cout << "Input id : ";
	cin >> id;
	cout << "Input withdraw money : ";
	cin >> money;
	for (int i = 0; i < index; ++i)
	{
		if (id == pArray[i].id)
		{
			if (pArray[i].balance < money)
			{
				cout << "You have run out of balance." << endl;
				return;
			}
			pArray[i].balance -= money;
			cout << "withdraw completed" << endl;
			return;
		}
	}

	cout << id << " is not a valid id." << endl;
}
void Inquire()
{
	if (index == 0)
	{
		cout <<"No Account" << endl;
	}
	for (int i = 0; i < index; ++i)
	{
		cout << "name :" << pArray[i].name << " id :" << pArray[i].id << " balance :" << pArray[i].balance << endl;
	}
}