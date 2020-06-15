#include"Data_Number_Option.h"
#include<iterator>

void data_New_Save(list<vector<char>>* data, vector<char>* temp, vector<int>* data_count) {
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

void data_Number_Count_Plus(list<vector<char>>* data, vector<char>* temp, vector<int>* data_count, int* max) {
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
				if (*max <= tempnum + 1)
					*max = tempnum + 1;
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