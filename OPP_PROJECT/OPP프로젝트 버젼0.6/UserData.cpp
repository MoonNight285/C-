#include"UserData.h"
#include<iostream>

using std::cout; using std::cin; using std::endl;

UserData::UserData() {
	name = NULL;
	id = -1;
	money = 0;
}

UserData::UserData(char* name, int id, int money) : id(id), money(money) {
	this->name = new char[20];
	for (int i = 0; i < 20; ++i)
		this->name[i] = name[i];
}

UserData::UserData(UserData& copy) {
	name = new char[20];
	for (int i = 0; i < 20; ++i)
		name[i] = copy.name[i];
	id = copy.id;
	money = copy.money;
}

UserData::~UserData() {
	delete[] name;
	id = -1;
	money = 0;
}

void UserData::moneySet(int point) {
	int temp;
	if (point < 0) {
		cout << "�ݾ��� �Է��ϼ���: ";
		cin >> temp;
	}

	if (point == -1) {
		money += temp;
		cout << "�Ա��� �Ϸ�Ǿ����ϴ�!" << endl;
	}
	else if (point == -2) {
		if (money >= temp) {
			money -= temp;
			cout << "����� �Ϸ�Ǿ����ϴ�!" << endl;
		}
		else
			cout << "�����ݾ��� �����մϴ�!" << endl;
	}
	else
		money += point;
}

int UserData::getID() const {
	return id;
}

int UserData::getMoney() const {
	return money;
}

char* UserData::getName() const {
	return name;
}

void UserData::showInfo() const {
	cout << "�̸�: " << name << endl;
	cout << "���̵�: " << id << endl;
	cout << "�����ݾ�: " << money << endl;
}