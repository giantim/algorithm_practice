#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check[50][50];
bool element[201];

int checkShape(int row, int column, int rowIndex, int colIndex)
{
	int number = -1;
	int comp = check[rowIndex][colIndex];
	if (rowIndex + 1 < row && colIndex + 2 < column)
	{
		if (comp == check[rowIndex + 1][colIndex] && comp == check[rowIndex + 1][colIndex + 1]
			&& comp == check[rowIndex + 1][colIndex + 2])
			number = 1;
	}
	if (rowIndex + 2 < row && colIndex - 1 >= 0)
	{
		if (comp == check[rowIndex + 1][colIndex] && comp == check[rowIndex + 2][colIndex]
			&& comp == check[rowIndex + 2][colIndex - 1])
			number = 2;
	}
	if (rowIndex + 2 < row && colIndex + 1 < column)
	{
		if (comp == check[rowIndex + 1][colIndex] && comp == check[rowIndex + 2][colIndex]
			&& comp == check[rowIndex + 2][colIndex + 1])
			number = 3;
	}
	if (rowIndex + 1 < row && colIndex - 2 >= 0)
	{
		if (comp == check[rowIndex + 1][colIndex] && comp == check[rowIndex + 1][colIndex - 1]
			&& comp == check[rowIndex + 1][colIndex - 2])
			number = 4;
	}
	if (rowIndex + 1 < row && colIndex - 1 >= 0 && colIndex + 1 < column)
	{
		if (comp == check[rowIndex + 1][colIndex] && comp == check[rowIndex + 1][colIndex - 1]
			&& comp == check[rowIndex + 1][colIndex + 1])
			number = 5;
	}
	return number;
}

bool checkUpSide(int number, int row, int column, int rowIndex, int colIndex) // true 장애물 없음 false 장애물 있음
{
	switch (number)
	{
	case 1:
		for (int i = rowIndex; i >= 0; i--)
		{
			if (check[i][colIndex + 1] != 0 || check[i][colIndex + 2] != 0)
			{
				return false;
			}
		}
		return true;
	case 2:
		for (int i = rowIndex + 1; i >= 0; i--)
		{
			if (check[i][colIndex - 1] != 0)
			{
				return false;
			}
		}
		return true;
	case 3:
		for (int i = rowIndex + 1; i >= 0; i--)
		{
			if (check[i][colIndex + 1] != 0)
			{
				return false;
			}
		}
		return true;
	case 4:
		for (int i = rowIndex; i >= 0; i--)
		{
			if (check[i][colIndex - 1] != 0 || check[i][colIndex - 2] != 0)
			{
				return false;
			}
		}
		return true;
	case 5:
		for (int i = rowIndex; i >= 0; i--)
		{
			if (check[i][colIndex - 1] != 0 || check[i][colIndex + 1] != 0)
			{
				return false;
			}
		}
		return true;
	default:
		return false;
	}
}

void erase(int number, int rowIndex, int colIndex)
{
	switch (number)
	{
	case 1:
		check[rowIndex][colIndex] = 0;
		check[rowIndex + 1][colIndex] = 0;
		check[rowIndex + 1][colIndex + 1] = 0;
		check[rowIndex + 1][colIndex + 2] = 0;
		break;
	case 2:
		check[rowIndex][colIndex] = 0;
		check[rowIndex + 1][colIndex] = 0;
		check[rowIndex + 2][colIndex] = 0;
		check[rowIndex + 2][colIndex - 1] = 0;
		break;
	case 3:
		check[rowIndex][colIndex] = 0;
		check[rowIndex + 1][colIndex] = 0;
		check[rowIndex + 2][colIndex] = 0;
		check[rowIndex + 2][colIndex + 1] = 0;
		break;
	case 4:
		check[rowIndex][colIndex] = 0;
		check[rowIndex + 1][colIndex] = 0;
		check[rowIndex + 1][colIndex - 1] = 0;
		check[rowIndex + 1][colIndex - 2] = 0;
		break;
	case 5:
		check[rowIndex][colIndex] = 0;
		check[rowIndex + 1][colIndex] = 0;
		check[rowIndex + 1][colIndex + 1] = 0;
		check[rowIndex + 1][colIndex - 1] = 0;
		break;
	default:
		break;
	}
}

int solution(vector<vector<int>> board)
{
	int answer = 0;

	for (int i = 0; i < 201; i++)
		element[i] = false;
	int row = board.size();
	int column = board[0].size();
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
			check[i][j] = board[i][j];
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (check[i][j] != 0 && element[check[i][j]] == false)
			{
				int shape = checkShape(row, column, i, j);
				if (shape == -1)
					element[check[i][j]] == true;
				else
				{
					if (checkUpSide(shape, row, column, i, j) == true)
					{
						erase(shape, i, j);
						i = 0;
						j = -1;
						element[check[i][j]] == true;
						answer = answer + 1;
					}
				}
			}
		}
	}

	return answer;
}

int main()
{
	vector<vector<int>> board;
	vector<int> v;

	/*{
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(4);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(4);
		v.push_back(4);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(3);
		v.push_back(0);
		v.push_back(4);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(2);
		v.push_back(3);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(5);
		v.push_back(5);
		board.push_back(v);
		v.clear();

		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(3);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(5);
		board.push_back(v);
		v.clear();

		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(0);
		v.push_back(5);
		board.push_back(v);
		v.clear();
	}*/

	{
		v.push_back(1);
		v.push_back(2);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();

		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(2);
		board.push_back(v);
		v.clear();

		v.push_back(1);
		v.push_back(1);
		v.push_back(0);
		v.push_back(0);
		board.push_back(v);
		v.clear();
	}

	cout << solution(board);
	return 0;
}
// [[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],
// [0,0,0,0,0,0,4,0,0,0],[0,0,0,0,0,4,4,0,0,0],[0,0,0,0,3,0,4,0,0,0],[0,0,0,2,3,0,0,0,5,5],
// [1,2,2,2,3,3,0,0,0,5],[1,1,1,0,0,0,0,0,0,5]]