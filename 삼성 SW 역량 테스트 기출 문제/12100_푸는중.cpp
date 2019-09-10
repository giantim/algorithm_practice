#include <iostream>
#include <vector>

using namespace std;

int board[20][20];
int arr[20][20];
int N;
int Max;

void up()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 0 && i + 1 < N)
			{
				int index = i + 1;
				while (index < N)
				{
					if (arr[index][j] != 0)
						break;
					index = index + 1;
				}
				if (arr[index][j] == arr[i][j])
				{
					arr[i][j] = arr[i][j] * 2;
					arr[index][j] = 0;
				}
				else
				{
					if (index != i + 1)
					{
						arr[i + 1][j] = arr[index][j];
						arr[index][j] = 0;
					}
				}
			}
		}
	}
}

void down()
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (arr[i][j] != 0 && i - 1 >= 0)
			{
				int index = i - 1;
				while (index >= 0)
				{
					if (arr[index][j] != 0)
						break;
					index = index - 1;
				}
				if (arr[index][j] == arr[i][j])
				{
					arr[i][j] = arr[index][j] * 2;
					arr[index][j] = 0;
				}
				else
				{
					if (index != i - 1)
					{
						arr[i - 1][j] = arr[index][j];
						arr[index][j] = 0;
					}
				}	
			}
		}
	}
}

void left()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 0 && j + 1 < N)
			{
				int index = j + 1;
				while (index < N)
				{
					if (arr[i][index] != 0)
						break;
					index = index + 1;
				}
				if (arr[i][j] == arr[i][index])
				{
					arr[i][j] = arr[i][j] * 2;
					arr[i][index] = 0;
				}
				else
				{
					if (index != j + 1)
					{
						arr[i][j + 1] = arr[i][index];
						arr[i][index] = 0;
					}
				}	
			}
		}
	}
}

void right()
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j >= 0; j--)
		{
			if (arr[i][j] != 0 && j - 1 >= 0)
			{
				int index = j - 1;
				while (index >= 0)
				{
					if (arr[i][index] != 0)
						break;
					index = index - 1;
				}
				if (arr[i][j] == arr[i][index])
				{
					arr[i][j] = arr[i][j] * 2;
					arr[i][index] = 0;
				}
				else
				{
					if (index != j - 1)
					{
						arr[i][j - 1] = arr[i][index];
						arr[i][index] = 0;
					}
				}
			}
		}
	}
}

void move(vector<int>& moveVector)
{
	for (int i = 0; i < moveVector.size(); i++)
	{
		switch (moveVector[i])
		{
		case 0:
			up();
			break;
		case 1:
			down();
			break;
		case 2:
			left();
			break;
		case 3:
			right();
			break;
		default:
			break;
		}
	}
}

int searchMax()
{
	int max = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	}
	return max;
}

void dfs(vector<int>& moveVector)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			arr[i][j] = board[i][j];
	}
	for (int i = 0; i < 4; i++)
	{
		moveVector.push_back(i);
		move(moveVector);
		int max = searchMax();
		Max = Max > max ? Max : max;
		dfs(moveVector);
		moveVector.pop_back();
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
			board[i][j] = 0;
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	vector<int> moveVector;
	Max = -1;
	dfs(moveVector);

	cout << Max;
	return 0;
}