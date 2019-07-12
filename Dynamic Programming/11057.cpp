#include <iostream>
using namespace std;

int arr[1001][11];

int main()
{
	int N;
	cin >> N;
	int i, j, k;
	long sum = 0;
	for (i = 0; i <= 9; i++)
		arr[1][i] = 1;
	for (i = 2; i <= N; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = j; k <= 9; k++)
				sum += arr[i - 1][k] % 10007;
			arr[i][j] = sum % 10007;
			sum = 0;
		}
	}
	for (i = 0; i <= 9; i++)
	{
		sum += arr[N][i];
	}
	cout << sum % 10007;
	return 0;
}