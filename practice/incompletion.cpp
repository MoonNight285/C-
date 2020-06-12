#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using std::vector; using std::list;
using std::cout; using std::endl;

void data_New_Save(list<vector<char>>* data, vector<char> *temp, vector<int> *data_count) {
	if ((*temp).empty() != true) {
		(*data).push_back((*temp));
		(*data_count).push_back(1);
	}
}

int data_Number_Count(list<vector<char>>* data, vector<char>* temp) {
	list<vector<char>>::iterator pos;
	for (pos = (*data).begin(); pos != (*data).end(); ++pos) {
		if ((*pos).size() != (*temp).size())
			continue;
		else
			return true;
	}
	return false;
}

void data_Number_Count_Plus(list<vector<char>>* data, vector<char>* temp, vector<int>* data_count) {
	list<vector<char>>::iterator pos;
	int flag = 0, count = -1, tempnum;
	for (pos = (*data).begin(); pos != (*data).end(); ++pos) {
		++count;
		if ((*pos).size() != (*temp).size())
			continue;
		else {
			for (int i = 0; i < (*pos).size(); ++i) {
				if ((*pos)[i] != (*temp)[i]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				tempnum = (*data_count)[count];
				(*data_count)[count] = tempnum + 1;
				break;
			}
			flag = 0;
		}
	}
	if ((*temp).empty() != true) {
		(*data).push_back((*temp));
		(*data_count).push_back(1);
	}
}

int main(void)
{
	list<vector<char>> data;
	list<vector<char>>::iterator pos;
	vector<char> temp;
	vector<int> data_count;
	FILE* fp = NULL;
	int ch, data_count_number = 0, max = 0,count = 0,top10 = 0;
	
	fopen_s(&fp, "text.txt", "rt");
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF)
			break;

		if (ch == '.' || ch == ',' || ch == ' ') {
			if (data.empty() == true)
				data_New_Save(&data, &temp, &data_count);
			else {
				if (data_Number_Count(&data, &temp) == false)
					data_New_Save(&data, &temp, &data_count);
				else
					data_Number_Count_Plus(&data, &temp, &data_count);
			}
			temp.clear();
		}
		else
			temp.push_back(ch);
	}
	
	cout << data.size() << endl;
	cout << data_count.size() << endl;
	for (pos = data.begin(); pos != data.end(); ++pos) {
		for (int i = 0; i < (*pos).size(); ++i)
			cout << (char)(*pos)[i];
		cout << ": " << data_count[data_count_number++] << endl;
	}
	data_count_number = 0;

	cout << "----- TOP 10 -----" << endl;
	return 0;
}
