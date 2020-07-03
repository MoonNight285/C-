// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <cstdio>

void nameCreate(char(*name)[20], int dataCount) {
	char temp[20];
	
	printf("이름을 입력하세요:");
	scanf_s("%s", temp, sizeof(temp));

	for (int i = 0; i < 20; ++i) {
		name[dataCount][i] = temp[i];
	}
}

void idCreate(int* id, int dataCount) {
	int temp;

	printf("아이디를 입력하세요:");
	scanf_s("%d", &temp);
	id[dataCount] = temp;
}

void moneyCreate(int* money, int dataCount) {
	int temp;

	printf("초기 입금 금액을 입력하세요:");
	scanf_s("%d", &temp);
	money[dataCount] = temp;
}

bool newAccount(char(*name)[20], int* id, int* money, int* datacount) {
	if (*datacount > 10) {
		printf("데이터의 수용량이 가득 찼습니다! \n");
		return false;
	}
	
	nameCreate(name, *datacount);
	idCreate(id, *datacount);
	moneyCreate(money, *datacount);
	(*datacount)++;

	return true;
}

int idSearch(int *id,int dataCount) {
	int temp;
	printf("id를 입력하세요:");
	scanf_s("%d", &temp);

	for (int i = 0; i < dataCount; ++i) {
		if (id[i] == temp)
			return i;
	}
	return -1;
}

void moneyInsert(int* id, int* money,int dataCount) {
	int moneytemp, idtemp;

	idtemp = idSearch(id, dataCount);
	if (idtemp != -1)
	{
		printf("금액을 입력하세요:");
		scanf_s("%d", &moneytemp);
		money[idtemp] += moneytemp;
	}
	printf("작업이 완료되었습니다!\n");
}

void moneyWithdraw(int* id, int* money, int dataCount) {
	int moneytemp, idtemp;

	idtemp = idSearch(id, dataCount);
	if (idtemp != -1)
	{
		printf("금액을 입력하세요:");
		scanf_s("%d", &moneytemp);
		if (money[idtemp] >= moneytemp) {
			money[idtemp] -= moneytemp;
			printf("작업이 완료되었습니다!\n");
		}
		else
			printf("보유금액이 부족합니다\n");
	}
}

void allShow(char(*name)[20], int* id, int* money, int dataCount) {
	for (int i = 0; i < dataCount; ++i) {
		printf("이름: %s \n",name[i]);
		printf("아이디: %d \n", id[i]);
		printf("보유금액: %d \n", money[i]);
		printf("\n");
	}
}

void menu() {
	printf("-----MENU-----\n");
	printf("1.계좌개설\n");
	printf("2.입금\n");
	printf("3.출금\n");
	printf("4.계좌정보 전체 출력\n");
	printf("5.프로그램 종료\n");
	printf("\n");
}

int main()
{
	char name[10][20];
	int id[10];
	int money[10];
	int point, exit = 0, dataCount = 0;

	while (true) {
		menu();
		scanf_s("%d", &point);

		switch (point)
		{
		case 1:
			newAccount(name, id, money, &dataCount);
			break;
		case 2:
			moneyInsert(id, money, dataCount);
			break;
		case 3:
			moneyWithdraw(id, money, dataCount);
			break;
		case 4:
			allShow(name, id, money, dataCount);
			break;
		case 5:
			exit = 1;
			break;
		}

		if (exit == 1)
			break;
	}
}
