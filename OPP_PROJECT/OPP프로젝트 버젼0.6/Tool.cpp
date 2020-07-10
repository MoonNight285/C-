#include"Tool.h"
#include"UserDataInherit.h"
#include<iostream>

using std::cout; using std::cin; using std::endl;

int Tool::idSearch() const {
	int temp;

	cout << "ID�� �Է��ϼ���: ";
	cin >> temp;
	for (int i = 0; i < dataCount; ++i)
		if (data[i]->getID() == temp)
			return i;
	return -1;
}

void Tool::nameSet(char* name) {
	cout << "�̸��� �Է��ϼ���: ";
	cin >> name;
}

int Tool::idSet() {
	int temp;
	cout << "ID�� �Է��ϼ���: ";
	cin >> temp;
	return temp;
}

int Tool::moneySet() {
	int temp;
	cout << "�ݾ��� �Է��ϼ���: ";
	cin >> temp;
	return temp;
}

int Tool::ratioSet() {
	int temp;
	cout << "���������� �Է��ϼ���: ";
	cin >> temp;
	return temp;
}

Rank Tool::rankSet() {
	char temp;
	cout << "����� �Է��ϼ���: ";
	cout << "����� A,B,C �� ���������ֽ��ϴ�." << endl;
	cout << "���� ����� �ϳ��� �����ϼ���" << endl;
	cin >> temp;
	if (temp == 'A' || temp == 'a')
		return Rank::A;
	else if (temp == 'B' || temp == 'b')
		return Rank::B;
	else
		return Rank::C;
}

int Tool::registration() {
	int temp;
	cout << "� ���·� ����Ͻǲ�����?" << endl;
	cout << "1. �����������" << endl;
	cout << "2. ����������" << endl;
	cin >> temp;
	return temp;
}

bool Tool::newAccount() {
	if (dataCount >= 10) {
		cout << "�������� ���뷮�� ���� á���ϴ�!" << endl;
		return false;
	}

	char name[20];
	int registrationResult = 0;

	registrationResult = registration();
	nameSet(name);
	if (registrationResult == 1)
		data[dataCount] = new NormalUserData(name, idSet(), moneySet(), ratioSet());
	else if (registrationResult == 2)
		data[dataCount] = new HighUserData(name, idSet(), moneySet(), ratioSet(), rankSet());
	else {
		cout << "�߸� �Է��ϼ̽��ϴ�!" << endl;
		cout << "�ٽ� ó������ ������ּ���" << endl;
		return false;
	}
	dataCount++;
	return true;
}

void Tool::moneyInsert() {
	int tempID;

	tempID = idSearch();
	if (tempID != -1)
		data[tempID]->moneySet(-1);
}

void Tool::moneyWithdraw() {
	int tempID;

	tempID = idSearch();
	if (tempID != -1)
		data[tempID]->moneySet(-2);
}

void Tool::allShow() const {
	for (int i = 0; i < dataCount; ++i) {
		data[i]->showInfo();
		cout << endl;
	}
}

void Tool::menu() const {
	cout << "-----MENU-----" << endl;
	cout << "1.���°���" << endl;
	cout << "2.�Ա�" << endl;
	cout << "3.���" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����" << endl << endl;
}