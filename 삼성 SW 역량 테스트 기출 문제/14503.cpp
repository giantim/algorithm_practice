#include <iostream>

using namespace std;

int N, M;
int board[50][50];

bool checkRange(int row, int column) 
{
	if (row >= 0 && row < N
		&& column >= 0 && column < M)
		return true;
	return false;
}

bool checkLeft(int row, int column, int direction)
{
	switch (direction)
	{
	case 0:
		if (checkRange(row, column - 1))
		{
			if (board[row][column - 1] == 0)
				return true;
			return false;
		}
		return false;
	case 1:
		if (checkRange(row - 1, column))
		{
			if (board[row - 1][column] == 0)
				return true;
			return false;
		}
		return false;
	case 2:
		if (checkRange(row, column + 1))
		{
			if (board[row][column + 1] == 0)
				return true;
			return false;
		}
		return false;
	case 3:
		if (checkRange(row + 1, column))
		{
			if (board[row + 1][column] == 0)
				return true;
			return false;
		}
		return false;
	default:
		break;
	}
}

void turnLeft(int& direction)
{
	switch (direction)
	{
	case 0:
		direction = 3;
		break;
	case 1:
		direction = 0;
		break;
	case 2:
		direction = 1;
		break;
	case 3:
		direction = 2;
		break;
	default:
		break;
	}
}

void goForward(int& row, int& column, int& direction)
{
	switch (direction)
	{
	case 0:
		direction = 3;
		column = column - 1;
		break;
	case 1:
		direction = 0;
		row = row - 1;
		break;
	case 2:
		direction = 1;
		column = column + 1;
		break;
	case 3:
		direction = 2;
		row = row + 1;
		break;
	default:
		break;
	}
}

bool checkBack(int row, int column, int direction)
{
	switch (direction)
	{
	case 0:
		if (checkRange(row + 1, column))
		{
			if (board[row + 1][column] == 1)
				return false;
			return true;
		}
		else
			return false;
		break;
	case 1:
		if (checkRange(row, column - 1))
		{
			if (board[row][column - 1] == 1)
				return false;
			return true;
		}
		else
			return false;
		break;
	case 2:
		if (checkRange(row - 1, column))
		{
			if (board[row - 1][column] == 1)
				return false;
			return true;
		}
		else
			return false;
		break;
	case 3:
		if (checkRange(row, column + 1))
		{
			if (board[row][column + 1] == 1)
				return false;
			return true;
		}
		else
			return false;
		break;
	default:
		break;
	}
}

void goBack(int& row, int& column, int direction)
{
	switch (direction)
	{
	case 0:
		row = row + 1;
		break;
	case 1:
		column = column - 1;
		break;
	case 2:
		row = row - 1;
		break;
	case 3:
		column = column + 1;
		break;
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
			board[i][j] = 0;
	}

	cin >> N >> M;
	int row, column;
	int direction;
	cin >> row >> column >> direction;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	int count = 0;
	bool run = true;
	int clean;
	while (run)
	{
		clean = 0;
		if (board[row][column] == 0)
		{
			count = count + 1;
			board[row][column] = 2;
		}
		while (!checkLeft(row, column, direction))
		{
			clean = clean + 1;
			if (clean == 4)
				break;
			turnLeft(direction);
		}
		if (clean != 4)
			goForward(row, column, direction);
		else if (clean == 4)
		{
			turnLeft(direction);
			if (checkBack(row, column, direction))
				goBack(row, column, direction);
			else
				run = false;
		}
	}

	cout << count;
	return 0;
}