#include <iostream>
using namespace std;

int print[1024];

int pow(int base, int factor)
{
	if (factor == 0)
		return 1;
	if (factor == 1)
		return base;
	int count = 1;
	int result = base;
	while (count < factor)
	{
		result *= base;
		count++;
	}
	return result;
}

int main()
{
	int T;
	cin >> T;
	int k;
	for (int i = 0; i < T; i++)
	{
		cin >> k;
		int power = pow(2, k);
		for (int j = 0; j < power - 1; j++)
			cin >> print[j];
		cout << '#' << i + 1 << ' ';
		int index = 0;
		for (int j = power; j >= 2; j /= 2)
		{
			int temp = j / 2;
			for (int a = 1; a <= pow(2, index); a++)
			{
				cout << print[(temp - 1) + (j * (a - 1))] << ' ';
			}
			cout << endl;
			index++;
		}
	}
	return 0;
}