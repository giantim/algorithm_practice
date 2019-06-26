#include <iostream>

using namespace std;

int main()
{
	int n, i, j, k;
	cin >> n;
	bool star = true;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			cout << " ";
		for (k = 1; k <= n - (j - 1); k++)
		{
			if (star)
			{
				cout << "*";
				star = false;
			}
			else
			{
				cout << " ";
				star = true;
			}
		}
		for (j = 1; j < i; j++)
		{
			if (star)
			{
				cout << "*";
				star = false;
			}
			else
			{
				cout << " ";
				star = true;
			}
		}
		cout << endl;
		star = true;
	}
	return 0;
}