// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include"Tool.h"
#include"UserDataInherit.h"
#include <iostream>
using std::cout; using std::endl; using std::cin;

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