#include <iostream>
using namespace std;

struct Pair
{
	double x;
	double y;
};

Pair arr[10000];
double sum = 0;

void cal(int index)
{
	double s = (arr[0].x * (arr[index].y - arr[index + 1].y))
		+ (arr[index].x * (arr[index + 1].y - arr[0].y))
		+ (arr[index + 1].x * (arr[0].y - arr[index].y));
	sum += s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	double x, y;
	for (i = 0; i < N; i++)
	{
		cin >> x >> y;
		arr[i].x = x;
		arr[i].y = y;
	}
	for (i = 1; i < N - 1; i++)
		cal(i);
	cout.setf(ios::fixed);
	cout.precision(1);
	if (sum < 0)
		sum *= -1;
	cout << sum / 2;
	return 0;
}