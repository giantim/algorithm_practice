#include <iostream>
using namespace std;

int arr[11];

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	int i;
	for (i = 4; i <= 10; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	int T, n;
	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> n;
		cout << arr[n] << endl;
	}
	return 0;
}