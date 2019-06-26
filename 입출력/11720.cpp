#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	string s;
	cin >> s;
	int a = 0;
	for (int i = 0; i < T; i++)
	{
		a += s[i] - 48;
	}
	cout << a;
	return 0;
}