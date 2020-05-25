#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	int total = 0;
	for (int i = 0; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0)
			total += i;
	}
	cout << "Total: " << total << endl;
	return 0;
}