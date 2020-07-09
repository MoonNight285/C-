// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using std::cout; using std::endl; using std::cin;

class UserData {
private:
	char* name;
	int id;
	int money;
public:
	UserData();
	UserData(char* name, int id, int money);
	UserData(UserData& copy);
	~UserData();
	virtual void moneySet(int point);
	int getID() const;
	int getMoney() const;
	char* getName() const;
	virtual void showInfo() const;
};

UserData::UserData() {
	name = NULL;
	id = -1;
	money = 0;
}

UserData::UserData(char* name, int id, int money) : id(id),money(money) {
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

enum class Rank {
	A,B,C
};

class NormalUserData : public UserData {
private:
	int ratio;
public:
	NormalUserData();
	NormalUserData(char* name, int id, int money, int ratio);
	~NormalUserData();
	int getRatio() const;
	void showInfo() const;
	void moneySet(int point);
};

NormalUserData::NormalUserData() { ratio = 0; }
NormalUserData::NormalUserData(char* name, int id, int money, int ratio) : UserData(name, id, money), ratio(ratio) {}
NormalUserData::~NormalUserData() {}
int NormalUserData::getRatio() const { return ratio; }
void NormalUserData::showInfo() const {
	UserData::showInfo();
	cout << "이율: " << ratio << endl;
}

void NormalUserData::moneySet(int point) {
	UserData::moneySet(point);
	UserData::moneySet((UserData::getMoney() / 100) * ratio);
}

class HighUserData : public NormalUserData {
private:
	Rank rank;
public:
	HighUserData();
	HighUserData(char* name, int id, int money, int ratio, Rank rank);
	~HighUserData();
	Rank getRank() const;
	void showInfo() const;
	void moneySet(int point);
};

HighUserData::HighUserData() { rank = Rank::C; }
HighUserData::HighUserData(char* name, int id, int money, int ratio, Rank rank) : NormalUserData(name, id, money, ratio), rank(rank) {}
HighUserData::~HighUserData() {}
Rank HighUserData::getRank() const { return rank; }
void HighUserData::showInfo() const {
	NormalUserData::showInfo();
	if (rank == Rank::A)
		cout << "등급: A" << endl;
	else if (rank == Rank::B)
		cout << "등급: B" << endl;
	else
		cout << "등급: C" << endl;
}

void HighUserData::moneySet(int point) {
	UserData::moneySet(point);
	if (rank == Rank::A)
		UserData::moneySet((UserData::getMoney() / 100) * (NormalUserData::getRatio() + 7));
	else if (rank == Rank::B)
		UserData::moneySet((UserData::getMoney() / 100) * (NormalUserData::getRatio() + 4));
	else if (rank == Rank::C)
		UserData::moneySet((UserData::getMoney() / 100) * (NormalUserData::getRatio() + 2));
}

class Tool {
private:
	UserData *data[10];
	int dataCount = 0;
	int idSearch() const;
	void nameSet(char* name);
	int idSet();
	int moneySet();
	int ratioSet();
	Rank rankSet();
	int registration();
public:
	bool newAccount();
	void moneyInsert();
	void moneyWithdraw();
	void allShow() const;
	void menu() const;
};

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

int main()
{
	Tool tool;
	int point, exit = 0;

	while (true) {
		tool.menu();
		cin >> point;

		switch (point)
		{
		case 1:
			tool.newAccount();
			break;
		case 2:
			tool.moneyInsert();
			break;
		case 3:
			tool.moneyWithdraw();
			break;
		case 4:
			tool.allShow();
			break;
		case 5:
			exit = 1;
			break;
		}

		if (exit == 1)
			break;
	}
}