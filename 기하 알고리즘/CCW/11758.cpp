#include <iostream>
using namespace std;

int P1[2];
int P2[2];
int P3[2];

int main()
{
	cin >> P1[0] >> P1[1]
		>> P2[0] >> P2[1]
		>> P3[0] >> P3[1];
	int S = ((P1[0] * (P2[1] - P3[1])) + (P2[0] * (P3[1] - P1[1])) + (P3[0] * (P1[1] - P2[1]))) / 2;
	if (S > 0)
		cout << 1;
	else if (S == 0)
		cout << 0;
	else
		cout << -1;
	return 0;
}