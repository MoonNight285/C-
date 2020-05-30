#include<iostream>
#include<iterator>
#include<string>
#include<set>

using std::cout; using std::endl;
using std::set; using std::string;

int main(void)
{
	const char * str = "������,���翵,����ǥ,���翵,�ڹ�ȣ,������,���翵,������,�ֽ���,�̼���,�ڿ���,�ڹ�ȣ,������,����ȯ,���缺,������,������";
	int countKim = 0, countLee = 0, countLEEJAEYOUNG = 0, temp_i = 0;
	char temp[20] = {0,}, KIM_DATA[3] = "��", LEE_DATA[3] = "��";
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
			if (strcmp(temp, "���翵") == 0)
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

	cout << "1.�达�� �̾��� ���� �� �� �ΰ���?" << endl << endl << "�达 : " << countKim << endl << "�̾� : " << countLee << endl << endl;
	cout << "\"���翵\"�̶� �̸��� �� �� �ݺ��ǳ���? : " << countLEEJAEYOUNG << endl << endl;
	cout << "�ߺ��� ������ �̸��� ����ϼ���." << endl << "[";
	for (pos = overlap.begin(); pos != overlap.end(); ++pos) {
		cout << *pos << " ";
	}
	cout << "]" << endl << endl;
	cout << "�ߺ��� ������ �̸��� ������������ �����Ͽ� ����ϼ���." << endl << "[";
	for (pos = result.begin(); pos != result.end(); ++pos) {
		cout << *pos << " ";
	}
	cout << "]" << endl << endl;

	return 0;
}
