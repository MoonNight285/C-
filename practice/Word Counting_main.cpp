#include<iostream>
#include"Data_Number_Option.h"
#include"Top10.h"

using std::vector; using std::list;
using std::cout; using std::endl;

int main(void)
{
	list<vector<char>> data;
	list<vector<char>>::iterator pos;
	vector<char> temp;
	vector<int> data_count;
	FILE* fp = NULL;
	int ch, data_count_number = 0, max = 1;
	
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
					data_Number_Count_Plus(&data, &temp, &data_count,&max);
			}
			temp.clear();
		}
		else
			temp.push_back(ch);
	}
	
	/*cout << data.size() << endl;
	cout << data_count.size() << endl;
	for (pos = data.begin(); pos != data.end(); ++pos) {
		for (int i = 0; i < (*pos).size(); ++i)
			cout << (char)(*pos)[i];
		cout << ": " << data_count[data_count_number++] << endl;
	}
	data_count_number = 0;*/

	cout << "----- TOP 10 -----" << endl;
	TOP10(&data, &data_count, &max);
	fclose(fp);

	return 0;
}
