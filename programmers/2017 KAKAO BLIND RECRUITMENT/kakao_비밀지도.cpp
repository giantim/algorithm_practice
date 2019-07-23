#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	char sol1[16][16];
	char sol2[16][16];
	int i, j;
	for (i = 0; i < n; i++)
	{
		int num1 = arr1[i];
		int num2 = arr2[i];
		for (j = n - 1; j >= 0; j--)
		{
			int remainder1 = num1 % 2;
			int remainder2 = num2 % 2;
			num1 /= 2;
			num2 /= 2;
			sol1[i][j] = remainder1;
			sol2[i][j] = remainder2;
		}
	}
	for (i = 0; i < n; i++)
	{
		string s;
		for (j = 0; j < n; j++)
		{
			if (sol1[i][j] == 1 || sol2[i][j] == 1)
				s += '#';
			else
				s += ' ';
		}
		answer.push_back(s);
	}
	return answer;
}