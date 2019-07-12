#include <iostream>
using namespace std;

long arr[101][11];

int main()
{
	int N;
	cin >> N;
	int i, j;
	for (i = 1; i <= 9; i++)
		arr[1][i] = 1;
	for (i = 2; i <= N; i++)
	{
		arr[i][0] = arr[i - 1][1];
		for (j = 1; j <= 9; j++)
		{
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
		}
	}
	long sum = 0;
	for (i = 0; i < 10; i++)
		sum += arr[N][i];
	cout << sum % 1000000000;
	return 0;
}