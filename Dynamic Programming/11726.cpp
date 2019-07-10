#include <iostream>
using namespace std;

int arr[1001];
int N;

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	int i;
	for (i = 3; i <= 1000; i++)
	{
		arr[i] = ((arr[i - 1] % 100007) + (arr[i - 2] % 100007)) % 10007 ;
	}
	cin >> N;
	cout << arr[N] ;
	return 0;
}