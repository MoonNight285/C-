#pragma once
#include"UserData.h"

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