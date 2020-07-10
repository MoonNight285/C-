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
		cout << "금액을 입력하세요: ";
		cin >> temp;
	}

	if (point == -1) {
		money += temp;
		cout << "입금이 완료되었습니다!" << endl;
	}
	else if (point == -2) {
		if (money >= temp) {
			money -= temp;
			cout << "출금이 완료되었습니다!" << endl;
		}
		else
			cout << "보유금액이 부족합니다!" << endl;
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
	cout << "이름: " << name << endl;
	cout << "아이디: " << id << endl;
	cout << "보유금액: " << money << endl;
}