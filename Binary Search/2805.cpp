#include <iostream>
using namespace std;

int partition(long long arr[], int left, int right)
{
	long long pivot = arr[left], temp, low = left, high = right + 1;
	do
	{
		do
			low++;
		while (low <= right && arr[low] < pivot);
		do
			high--;
		while (high >= left && arr[high] > pivot);
		if (low < high) 
		{
			temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	} while (low < high);
	temp = arr[left];
	arr[left] = arr[high];
	arr[high] = temp;
	return high;
}

void quick_sort(long long arr[], int left, int right)
{
	if (left < right)
	{
		long long q = partition(arr, left, right);
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}

long long tree[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long N, M;
	cin >> N >> M;
	int i;
	for (i = 0; i < N; i++)
		cin >> tree[i];
	quick_sort(tree, 0, N - 1);
	long long left, right, mid, total;
	long long result = 0;
	left = 0;
	right = tree[N - 1];
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		total = 0;
		for (i = 0; i < N; i++)
		{
			if (mid < tree[i])
				total += tree[i] - mid;
		}
		if (total >= M)
		{
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result;
	return 0;
}