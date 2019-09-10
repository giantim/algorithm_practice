#include <iostream>

using namespace std;

int board[501][501];
int N, M;

int shape1(int row, int column)
{
	if (row + 3 <= N)
		return board[row][column] + board[row + 1][column]
		+ board[row + 2][column] + board[row + 3][column];
	return 0;
}

int shape2(int row, int column)
{
	if (column + 3 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row][column + 2] + board[row][column + 3];
	return 0;
}

int shape3(int row, int column)
{
	if (row + 1 <= N && column + 1 <= M)
		return board[row][column] + board[row + 1][column]
		+ board[row][column + 1] + board[row + 1][column + 1];
	return 0;
}

int shape4(int row, int column)
{
	if (row + 2 <= N && column + 1 <= M)
		return board[row][column] + board[row + 1][column]
		+ board[row + 2][column] + board[row + 2][column + 1];
	return 0;
}

int shape5(int row, int column)
{
	if (row + 2 <= N && column - 1 >= 1)
		return board[row][column] + board[row + 1][column]
		+ board[row + 2][column] + board[row + 2][column - 1];
	return 0;
}

int shape6(int row, int column)
{
	if (row + 1 <= N && column + 2 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row][column + 2] + board[row + 1][column + 2];
	return 0;
}

int shape7(int row, int column)
{
	if (row - 1 >= 1 && column + 2 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row][column + 2] + board[row - 1][column + 2];
	return 0;
}

int shape8(int row, int column)
{
	if (row - 2 >= 1 && column + 1 <= M)
		return board[row][column] + board[row - 1][column]
		+ board[row - 2][column] + board[row - 2][column + 1];
	return 0;
}

int shape9(int row, int column)
{
	if (row - 2 >= 1 && column - 1 >= 1)
		return board[row][column] + board[row - 1][column]
		+ board[row - 2][column] + board[row - 2][column - 1];
	return 0;
}

int shape10(int row, int column)
{
	if (row + 1 <= N && column - 2 >= 1)
		return board[row][column] + board[row][column - 1]
		+ board[row][column - 2] + board[row + 1][column - 2];
	return 0;
}

int shape11(int row, int column)
{
	if (row - 1 >= 1 && column - 2 >= 1)
		return board[row][column] + board[row][column - 1]
		+ board[row][column - 2] + board[row - 1][column - 2];
	return 0;
}

int shape12(int row, int column)
{
	if (row + 2 <= N && column + 1 <= M)
		return board[row][column] + board[row + 1][column]
		+ board[row + 1][column + 1] + board[row + 2][column + 1];
	return 0;
}

int shape13(int row, int column)
{
	if (row + 2 <= N && column - 1 >= 1)
		return board[row][column] + board[row + 1][column]
		+ board[row + 1][column - 1] + board[row + 2][column - 1];
	return 0;
}

int shape14(int row, int column)
{
	if (row - 1 >= 1 && column + 2 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row - 1][column + 1] + board[row - 1][column + 2];
	return 0;
}

int shape15(int row, int column)
{
	if (row + 1 <= N && column + 2 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row + 1][column + 1] + board[row + 1][column + 2];
	return 0;
}

int shape16(int row, int column)
{
	if (row - 2 >= 1 && column + 1 <= M)
		return board[row][column] + board[row - 1][column]
		+ board[row - 1][column + 1] + board[row - 2][column + 1];
	return 0;
}

int shape17(int row, int column)
{
	if (row - 2 >= 1 && column - 1 >= 1)
		return board[row][column] + board[row - 1][column]
		+ board[row - 1][column - 1] + board[row - 2][column - 1];
	return 0;
}

int shape18(int row, int column)
{
	if (row - 1 >= 1 && column - 2 >= 1)
		return board[row][column] + board[row][column - 1]
		+ board[row - 1][column - 1] + board[row - 1][column - 2];
	return 0;
}

int shape19(int row, int column)
{
	if (row + 1 <= N && column - 2 >= 1)
		return board[row][column] + board[row][column - 1]
		+ board[row + 1][column - 1] + board[row + 1][column - 2];
	return 0;
}

int shape20(int row, int column)
{
	if (row + 1 <= N && column + 2 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row][column + 2] + board[row + 1][column + 1];
	return 0;
}

int shape21(int row, int column)
{
	if (row - 1 >= 1 && column + 2 <= M)
		return board[row][column] + board[row][column + 1]
		+ board[row][column + 2] + board[row - 1][column + 1];
	return 0;
}

int shape22(int row, int column)
{
	if (row - 2 >= 1 && column + 1 <= M)
		return board[row][column] + board[row - 1][column]
		+ board[row - 2][column] + board[row - 1][column + 1];
	return 0;
}

int shape23(int row, int column)
{
	if (row - 2 >= 1 && column - 1 >= 1)
		return board[row][column] + board[row - 1][column]
		+ board[row - 2][column] + board[row - 1][column - 1];
	return 0;
}

int shape24(int row, int column)
{
	if (row + 1 <= N && column - 2 >= 1)
		return board[row][column] + board[row][column - 1]
		+ board[row][column - 2] + board[row + 1][column - 1];
	return 0;
}

int shape25(int row, int column)
{
	if (row - 1 >= 1 && column - 2 >= 1)
		return board[row][column] + board[row][column - 1]
		+ board[row][column - 2] + board[row - 1][column - 1];
	return 0;
}

int shape26(int row, int column)
{
	if (row + 2 <= N && column + 1 <= M)
		return board[row][column] + board[row + 1][column]
		+ board[row + 2][column] + board[row + 1][column + 1];
	return 0;
}

int shape27(int row, int column)
{
	if (row + 2 <= N && column - 1 >= 1)
		return board[row][column] + board[row + 1][column]
		+ board[row + 2][column] + board[row + 1][column - 1];
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
			board[i][j] = 0;
	}

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int num;
			cin >> num;
			board[i][j] = num;
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (max < shape1(i, j))
				max = shape1(i, j);

			if (max < shape2(i, j))
				max = shape2(i, j);

			if (max < shape3(i, j))
				max = shape3(i, j);

			if (max < shape4(i, j))
				max = shape4(i, j);

			if (max < shape5(i, j))
				max = shape5(i, j);

			if (max < shape6(i, j))
				max = shape6(i, j);

			if (max < shape7(i, j))
				max = shape7(i, j);

			if (max < shape8(i, j))
				max = shape8(i, j);

			if (max < shape9(i, j))
				max = shape9(i, j);

			if (max < shape10(i, j))
				max = shape10(i, j);

			if (max < shape11(i, j))
				max = shape11(i, j);

			if (max < shape12(i, j))
				max = shape12(i, j);

			if (max < shape13(i, j))
				max = shape13(i, j);

			if (max < shape14(i, j))
				max = shape14(i, j);

			if (max < shape15(i, j))
				max = shape15(i, j);

			if (max < shape16(i, j))
				max = shape16(i, j);

			if (max < shape17(i, j))
				max = shape17(i, j);

			if (max < shape18(i, j))
				max = shape18(i, j);

			if (max < shape19(i, j))
				max = shape19(i, j);

			if (max < shape20(i, j))
				max = shape20(i, j);

			if (max < shape21(i, j))
				max = shape21(i, j);

			if (max < shape22(i, j))
				max = shape22(i, j);

			if (max < shape23(i, j))
				max = shape23(i, j);

			if (max < shape24(i, j))
				max = shape24(i, j);

			if (max < shape25(i, j))
				max = shape25(i, j);

			if (max < shape26(i, j))
				max = shape26(i, j);

			if (max < shape27(i, j))
				max = shape27(i, j);
		}
	}

	cout << max;
	return 0;
}