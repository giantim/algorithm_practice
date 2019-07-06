#include <iostream>
using namespace std;

int score[100];
int temp[10000];
bool total[10000];

int main()
{
	int T, N;
	cin >> T;
	int i, j;
	for (int i = 0; i < T; i++)
	{
		for (j = 0; j < 10000; j++)
			temp[j] = 0;
		for (j = 0; j < 10000; j++)
			total[j] = false;
		cin >> N;
		for (j = 0; j < N; j++)
			cin >> score[j];
		int count = 1;
		int index = 0;
		while (index < N)
		{
			int bound = count;
			for (j = 0; j < bound; j++)
			{
				if (!total[score[index] + temp[j]])
				{
					total[score[index] + temp[j]] = true;
					temp[count++] = score[index] + temp[j];
				}
			}
			index++;
		}
		cout << "#" << i + 1 << ' ' << count << endl;
	}
	return 0;
}