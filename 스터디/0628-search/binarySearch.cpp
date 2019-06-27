#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int key)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] > key)
			return binarySearch(arr, l, mid - 1, key);
		return binarySearch(arr, mid + 1, r, key);
	}
	return -1;
}

int binarySearch2(int arr[], int l, int r, int key)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] == key)
			return m;
		if (arr[m] < key)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 11;
	int result = binarySearch2(arr, 0, n - 1, key);
	(result == -1) ? printf("Element is not present in array") :
		printf("Element is present at indes %d", result);
	return 0;
}