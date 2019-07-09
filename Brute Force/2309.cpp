#include <iostream>
using namespace std;

int arr[9];
int index1, index2;

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

void setIndex(int subtract)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (arr[i] + arr[j] == subtract)
			{
				index1 = i;
				index2 = j;
				return;
			}
		}
	}
}

int main()
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	quick_sort(arr, 0, 8);
	int subtract = sum - 100;
	setIndex(subtract);
	for (int i = 0; i < 9; i++)
	{
		if (i == index1 || i == index2)
			continue;
		else
			cout << arr[i] << endl;
	}
	return 0;
}