#include <iostream>

using namespace std;

int main()
{
	int n, i;
	cin >> n;
	int* arr = new int[n];
	for (i = 0; i < n; i++)
		cin >> arr[i];
	int max = arr[0];
	int min = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] >= max)
			max = arr[i];
		if (arr[i] <= min)
			min = arr[i];
	}
	cout << min << " " << max;
	return 0;
}