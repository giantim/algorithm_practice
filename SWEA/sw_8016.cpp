#include <iostream>
using namespace std;

long long left(long long N)
{
	if (N == 1)
		return 0;
	else
		return 2 * (N - 1) * (N - 1);
}

long long right(long long N)
{
	if (N == 1)
		return 0;
	else
		return (N - 1) * ((2 * (N - 1)) + 4);
}

int main()
{
	int T;
	cin >> T;
	long long N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << '#' << i + 1 << ' ' << left(N) + 1 << ' ' << right(N) + 1 << endl;
	}
	return 0;
}