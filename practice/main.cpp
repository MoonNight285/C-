#include<iostream>
#include<iterator>
#include<string>
#include<set>

using std::cout; using std::endl;
using std::set; using std::string;

int main(void)
{
	const char * str = "이유덕,이재영,권종표,이재영,박민호,강상희,이재영,김지완,최승혁,이성연,박영서,박민호,전경헌,송정환,김재성,이유덕,전경헌";
	int countKim = 0, countLee = 0, countLEEJAEYOUNG = 0, temp_i = 0;
	char temp[20] = {0,}, KIM_DATA[3] = "김", LEE_DATA[3] = "이";
	set<string> result, overlap; set<string>::iterator pos;

	for (int i = 0; str[i] != 0; ++i) {
		if (str[i] != ',') {
			temp[temp_i] = str[i];
			temp_i++;
		}
		else {
			if (temp[0] == KIM_DATA[0] && temp[1] == KIM_DATA[1])
				countKim++;
			if (temp[0] == LEE_DATA[0] && temp[1] == LEE_DATA[1])
				countLee++;
			if (strcmp(temp, "이재영") == 0)
				countLEEJAEYOUNG++;
			pos = result.find(temp);
			if (pos != result.end())
				overlap.insert(temp);
			result.insert(temp);
			temp_i = 0;
			for (int x = 0; x < 20; x++)
				temp[x] = 0;
		}
	}

	cout << "1.김씨와 이씨는 각각 몇 명 인가요?" << endl << endl << "김씨 : " << countKim << endl << "이씨 : " << countLee << endl << endl;
	cout << "\"이재영\"이란 이름이 몇 번 반복되나요? : " << countLEEJAEYOUNG << endl << endl;
	cout << "중복을 제거한 이름을 출력하세요." << endl << "[";
	for (pos = overlap.begin(); pos != overlap.end(); ++pos) {
		cout << *pos << " ";
	}
	cout << "]" << endl << endl;
	cout << "중복을 제거한 이름을 오름차순으로 정렬하여 출력하세요." << endl << "[";
	for (pos = result.begin(); pos != result.end(); ++pos) {
		cout << *pos << " ";
	}
	cout << "]" << endl << endl;

	return 0;
}
