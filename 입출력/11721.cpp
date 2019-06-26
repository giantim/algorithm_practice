#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int count = 0;
	while (count != s.length())
	{
		cout << s[count++];
		if (count % 10 == 0)
			cout << endl;
	}
	return 0;
}