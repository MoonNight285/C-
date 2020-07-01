#include<iostream>
#include<string>

using std::string;
using std::cout; using std::endl;

string solution(string s) {
	if (s.length() % 2 == 0) 
		return s.substr(s.length() / 2 - 1, 2);
	else 
		return s.substr(s.length() / 2, 1);
}

int main(void)
{
	string str;
	str = solution("abcde");
	cout << str << endl;
	return 0;
}
