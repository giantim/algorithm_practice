#include <iostream>

using namespace std;

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)
			cout << " ";
		cout << "*";
		if (i == 1)
			cout << endl;
		else
		{
			for (j = 1; j <= (i * 2) - 3; j++)
				cout << " ";
			cout << "*" << endl;
		}
	}
	for (i = 0; i < (2 * n) - 1; i++)
		cout << "*";
	return 0;
}