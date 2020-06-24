#include<iostream>
#include<vector>

using std::vector;
using std::cout; using std::endl;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int count = 0, compare;
	
	for (int i = 0; i < reserve.size(); ++i) {
		compare = reserve[i];
		for (int x = 0; x < lost.size(); ++x) {
			if (lost[x] == compare) {
				lost[x] = -1;
				reserve[i] = -1;
				break;
			}
		}
	}


	for (int i = 0; i < reserve.size(); ++i) {
		compare = reserve[i];
		if (compare == -1)
			continue;
		for (int x = 0; x < lost.size(); ++x) {
			if (lost[x] == compare - 1 || lost[x] == compare + 1) {
				lost[x] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); ++i)
		if (lost[i] != -1)
			count++;
	
	return n - count;
}

int main(void)
{
	vector<int> lost;
	vector<int> reserve;

	lost.push_back(2);
	lost.push_back(4);

	reserve.push_back(1);
	reserve.push_back(3);
	reserve.push_back(5);

	cout << solution(5, lost, reserve) << endl;
	return 0;
}
