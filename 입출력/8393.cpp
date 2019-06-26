#include <iostream>

using namespace std;

int main()
{
	int a;
	cin >> a;
	int answer = 0;
	for (int i = 1; i <= a; i++)
		answer += i;
	cout << answer;
	return 0;
}