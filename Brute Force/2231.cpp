#include <iostream>
using namespace std;

int getFigure(int N)
{
	int count = 0;
	while (N > 0)
	{
		N = N / 10;
		count++;
	}
	return count;
}

int pow(int number, int i)
{
	if (i == 0)
		return 1;
	else if (i == 1)
		return number;
	else
	{
		int original = number;
		while (i > 1)
		{
			number = number * original;
			i--;
		}
		return number;
	}
}

int cal(int N)
{
	int sum = N;
	int figure = getFigure(N);
	for (int i = figure; i >= 1; i--)
	{
		int power = pow(10, i - 1);
		int digit = N / power;
		sum += digit;
		N = N - (digit * power);
	}
	return sum;
}

int main()
{
	int N;
	cin >> N;
	int start = N - (getFigure(N) * 9);
	for (int i = start; i < N; i++)
	{
		int answer = cal(i);
		if (answer == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}