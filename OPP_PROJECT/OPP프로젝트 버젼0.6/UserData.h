#pragma once
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

enum class Rank {
	A, B, C
};