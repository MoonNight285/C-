#include"Top10.h"
#include<iostream>
#include<iterator>

using std::cout;
using std::endl;

void TOP10(list<vector<char>>* data, vector<int>* data_count, int* max) {
	list<vector<char>>::iterator pos;
	int count = 0, search = 0;
	while (1) {
		for (pos = (*data).begin(); pos != (*data).end(); ++pos) {
			if (count == 10)
				break;
			if ((*data_count)[search] == (*max)) {
				for (int i = 0; i < (*pos).size(); ++i)
					cout << (char)(*pos)[i];
				cout << ": " << (*data_count)[search] << endl;
				count++;
			}
			search++;
		}
		if (count == 10 || (*max) == 0)
			break;
		else {
			search = 0;
			(*max)--;
		}
	}
}