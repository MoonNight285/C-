#include"Tool.h"
#include"UserDataInherit.h"
#include<iostream>

using std::cout; using std::cin; using std::endl;

int Tool::idSearch() const {
	int temp;

	cout << "ID를 입력하세요: ";
	cin >> temp;
	for (int i = 0; i < dataCount; ++i)
		if (data[i]->getID() == temp)
			return i;
	return -1;
}

void Tool::nameSet(char* name) {
	cout << "이름을 입력하세요: ";
	cin >> name;
}

int Tool::idSet() {
	int temp;
	cout << "ID를 입력하세요: ";
	cin >> temp;
	return temp;
}

int Tool::moneySet() {
	int temp;
	cout << "금액을 입력하세요: ";
	cin >> temp;
	return temp;
}

int Tool::ratioSet() {
	int temp;
	cout << "이율정보를 입력하세요: ";
	cin >> temp;
	return temp;
}

Rank Tool::rankSet() {
	char temp;
	cout << "등급을 입력하세요: ";
	cout << "등급은 A,B,C 로 나누어져있습니다." << endl;
	cout << "위의 등급중 하나를 선택하세요" << endl;
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
	cout << "어떤 계좌로 등록하실껀가요?" << endl;
	cout << "1. 보통은행계좌" << endl;
	cout << "2. 우대은행계좌" << endl;
	cin >> temp;
	return temp;
}

bool Tool::newAccount() {
	if (dataCount >= 10) {
		cout << "데이터의 수용량이 가득 찼습니다!" << endl;
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
		cout << "잘못 입력하셨습니다!" << endl;
		cout << "다시 처음부터 등록해주세요" << endl;
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
	cout << "1.계좌개설" << endl;
	cout << "2.입금" << endl;
	cout << "3.출금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료" << endl << endl;
}