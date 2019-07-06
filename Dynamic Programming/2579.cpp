#include <iostream>
using namespace std;

int stair[300];
int total[300];

int main()
{
	int T, i;
	int count = 1;
	cin >> T;
	for (i = 0; i < T; i++)
		cin >> stair[i];
	total[0] = stair[0];
	total[1] = stair[0] + stair[1];
	total[2] = stair[0] > stair[1] ? stair[0] + stair[2] : stair[1] + stair[2];
	for (i = 3; i <= T - 1; i++)
	{
		if (total[i - 3] + stair[i - 1] > total[i - 2])
			total[i] = total[i - 3] + stair[i - 1] + stair[i];
		else
			total[i] = total[i - 2] + stair[i];
	}
	cout << total[T - 1] << endl;
	return 0;
}