#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
	int pivot = arr[l];
	int temp;
	int low = l, high = r + 1;
	do
	{
		do
			low++;
		while (low <= r && arr[low] < pivot);
		do
			high--;
		while (high >= l && arr[high] > pivot);
		if (low < high)
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	} while (low < high);
	temp = arr[l];
	arr[l] = arr[high];
	arr[high] = temp;
	return high;
}

void quick_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int q = partition(arr, l, r);
		quick_sort(arr, l, q - 1);
		quick_sort(arr, q + 1, r);
	}
}

int arr[100000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, i, j;
	cin >> T;	
	for (i = 0; i < T; i++)
		cin >> arr[i];
	quick_sort(arr, 0, T - 1);
	cin >> j;
	int num, l, r;
	bool found = false;
	for (i = 0; i < j; i++)
	{
		found = false;
		cin >> num;
		l = 0;
		r = T - 1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (arr[m] == num)
			{
				printf("1\n");
				found = true;
			}
			if (arr[m] < num)
				l = m + 1;
			else
				r = m - 1;
		}
		if (!found)
			printf("0\n");
	}
	return 0;
}