#pragma once
#include"UserData.h"

class Tool {
private:
	UserData* data[10];
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