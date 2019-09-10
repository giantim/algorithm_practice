#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[8][8];
int arr[8][8];

class Wall
{
public:
	int row;
	int col;
	int postRow;
	int postCol;

	Wall()
	{
		this->row = -1;
		this->col = -1;
		this->postRow = -1;
		this->postCol = -1;
	}

	Wall(int i, int j)
	{
		this->row = i;
		this->col = j;
		this->postRow = -1;
		this->postCol = -1;
	}

	void modiPos(int i, int j)
	{
		this->postRow = this->row;
		this->postCol = this->col;
		this->row = i;
		this->col = j;
	}
};

vector<Wall> v;

void copy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = board[i][j];
	}
}

bool checkRange(int i, int j)
{
	if (i >= 0 && i < N
		&& j >= 0 && j < M)
		return true;
	return false;
}

void dfs(int row, int col)
{
	for (int i = row; i < N; i++)
	{
		for (int j = col; j < M; j++)
		{
			if (arr[i][j] == 2)
			{
				if (arr[i][j + 1] == 0 && checkRange(i, j + 1))
				{
					arr[i][j + 1] = 2;
					dfs(i, j + 1);
				}
				if (arr[i + 1][j] == 0 && checkRange(i + 1, j))
				{
					arr[i + 1][j] = 2;
					dfs(i + 1, j);
				}
				if (arr[i][j - 1] == 0 && checkRange(i, j - 1))
				{
					arr[i][j - 1] = 2;
					dfs(i, j - 1);
				}
				if (arr[i - 1][j] == 0 && checkRange(i - 1, j))
				{
					arr[i - 1][j] = 2;
					dfs(i - 1, j);
				}
			}
		}
	}
}

int countZero()
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				result = result + 1;
		}
	}
	return result;
}

bool findZero(int wallIndex, int row, int col)
{
	bool find = false;
	int i = row;
	int j = col + 1;
	for (; j < M; j++)
	{
		if (board[i][j] == 0)
		{
			board[v[wallIndex].row][v[wallIndex].col] = 0;
			board[i][j] = 1;
			v[wallIndex].modiPos(i, j);
			find = true;
			break;
		}
	}
	if (find == true)
		return true;
	else
	{
		for (i = row + 1; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (board[i][j] == 0)
				{
					board[v[wallIndex].row][v[wallIndex].col] = 0;
					board[i][j] = 1;
					v[wallIndex].modiPos(i, j);
					find = true;
					break;
				}
			}
			if (find == true)
				break;
		}
		return find;
	}
}

bool moveThirdWall()
{
	return findZero(2, v[2].row, v[2].col);
}

bool moveSecondWall()
{
	if (findZero(1, v[1].row, v[1].col) == true)
	{
		findZero(2, v[1].row, v[1].col);
		return true;
	}
	else
		return false;
}

bool moveFirstWall()
{
	if (findZero(0, v[0].row, v[0].col) == true)
	{
		findZero(1, v[0].row, v[0].col);
		findZero(2, v[1].row, v[1].col);
		return true;
	}
	else
		return false;
}

bool moveWall()
{
	if (moveThirdWall() == true)
		return true;
	else
	{
		if (moveSecondWall() == true)
			return true;
		else
		{
			if (moveFirstWall() == true)
				return true;
			else
				return false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
			arr[i][j] = 0;
		}
	}

	cin >> N >> M;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				v.push_back(Wall(i, j));
				board[i][j] = 1;
			}
			if (v.size() == 3)
				break;
		}
		if (v.size() == 3)
			break;
	}

	int max = -1;
	do
	{
		copy();
		dfs(0, 0);
		int zero = countZero();
		max = max < zero ? zero : max;
	} while (moveWall());

	cout << max;
	return 0;
}