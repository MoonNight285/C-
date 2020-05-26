#include<iostream>

using std::cout;
using std::endl;

bool three_Check(int number2, int number3, int number4) {
	if (number2 == 3 || number3 == 3 || number4 == 3)
		return true;
	else
		return false;
}

int main(void)
{
	int thousand = 0, hundred = 0, ten = 0, one = 0;
	int count = 0;

	while (!(thousand == 2 && hundred == 4)) {
		if (three_Check(hundred, ten, one))
			count++;
		one++;
		if (one == 10) {
			one = 0;
			ten++;
		}
		if (ten == 6) {
			ten = 0;
			hundred++;
		}
		if (hundred == 10) {
			hundred = 0;
			thousand++;
		}
	}
	cout << "total count: " << count * 60 << endl;
	return 0;

}
