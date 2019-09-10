#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, A, B, C;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		v.push_back(A);
	}
	cin >> B >> C;
	long long int count = 0;
	for (int i = 0; i < N; i++)
	{
		int number = v[i];
		number = number - B;
		if (number >= 0)
		{
			int quotient = number / C;
			if (number % C != 0)
				quotient = quotient + 1;
			count = count + quotient + 1;
		}
		else
			count = count + 1;
	}
	cout << count;
	return 0;
}