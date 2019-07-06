#include <iostream>
using namespace std;

bool arr[50][50];
int minArr[50][50];

// W = true, B = false
void checkW(int row, int column) // Èò Ã¼½ºÆÇÀÌ¶û ºñ±³
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (!arr[row + i][column + j])
						count++;
				}
				else
				{ 
					if (arr[row + i][column + j])
						count++;
				}	
			}
			else
			{
				if (j % 2 == 0)
				{
					if (arr[row + i][column + j])
						count++;
				}
				else
				{
					if (!arr[row + i][column + j])
						count++;
				}
			}
		}
	}
	minArr[row][column] = count >= 64 - count ? 64 - count : count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int i, j;
	char chess;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> chess;
			if (chess == 'W')
				arr[i][j] = true;
			else
				arr[i][j] = false;
		}
	}
	for (i = 0; i < N - 7; i++)
	{
		for (j = 0; j < M - 7; j++)
			checkW(i, j);
	}
	int result = 65;
	for (i = 0; i < N - 7; i++)
	{
		for (j = 0; j < M - 7; j++)
		{
			if (result > minArr[i][j])
				result = minArr[i][j];
		}
	}
	cout << result;
	return 0;
}