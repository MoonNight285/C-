#include"UserDataInherit.h"
#include<iostream>

using std::cout; using std::cin; using std::endl;

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