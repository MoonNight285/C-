#include<iostream>
#include<iterator>
#include<set>

using std::cout; using std::endl;
using std::set;

int main(void)
{
	set<int> generator;
	set<int>::iterator pos;
	int selfnumber = 0;

	for (int i = 1; i < 5001; ++i) {
		if (i < 10)
			generator.insert(i + i);
		else if (i < 100)
			generator.insert((i / 10) + (i % 10) + i);
		else if (i < 1000)
			generator.insert((i / 100) + ((i % 100) / 10) + ((i % 100) % 10) + i);
		else
			generator.insert((i / 1000) + ((i % 1000) / 100) + (((i % 1000) % 100) / 10) + (((i % 1000) % 100) % 10) + i);
	}

	for (int i = 1; i < 5001; ++i) {
		pos = generator.find(i);
		if (pos == generator.end())
			selfnumber += i;
	}
	cout << "self number total : " << selfnumber << endl;

	return 0;
}
