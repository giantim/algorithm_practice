#include <iostream>
#include <vector>

using namespace std;

int board[101][101];
char direction[10001];
int N;

bool checkIndex(int rowIndex, int colIndex)
{
	if ((rowIndex >= 1 && rowIndex <= N)
		&& (colIndex >= 1 && colIndex <= N))
		return true;
	return false;
}

void modiGo(string& go, char c)
{
	if (c == ' ')
		return;
	else if (c == 'D')
	{
		if (go == "colplus")
			go = "rowplus";
		else if (go == "colminus")
			go = "rowminus";
		else if (go == "rowplus")
			go = "colminus";
		else
			go = "colplus";
	}
	else
	{
		if (go == "colplus")
			go = "rowminus";
		else if (go == "colminus")
			go = "rowplus";
		else if (go == "rowplus")
			go = "colplus";
		else
			go = "colminus";
	}
}

void modiIndex(string go, int& headRow, int& headCol)
{
	if (go == "colplus")
		headCol = headCol + 1;
	else if (go == "colminus")
		headCol = headCol - 1;
	else if (go == "rowplus")
		headRow = headRow + 1;
	else
		headRow = headRow - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			board[i][j] = 0;
	}
	for (int i = 0; i < 10001; i++)
		direction[i] = ' ';

	int K;
	cin >> N >> K;
	int row, column;
	for (int i = 0; i < K; i++)
	{
		cin >> row >> column;
		board[row][column] = 1;
	}

	int L;
	cin >> L;
	int second;
	char direct;
	for (int i = 0; i < L; i++)
	{
		cin >> second >> direct;
		direction[second] = direct;
	}

	int headClock = 0;
	int tailClock = 0;
	int headRow = 1;
	int headCol = 1;
	int tailRow = 1;
	int tailCol = 1;
	board[headRow][headCol] = 2;
	string headGo = "colplus";
	string tailGo = "colplus";
	while (true)
	{
		modiIndex(headGo, headRow, headCol);
		headClock = headClock + 1;
		if (!checkIndex(headRow, headCol))
			break;
		if (board[headRow][headCol] == 2)
			break;
		if (board[headRow][headCol] == 1)
			board[headRow][headCol] = 2;
		else if (board[headRow][headCol] == 0)
		{
			board[headRow][headCol] = 2;
			board[tailRow][tailCol] = 0;
			modiIndex(tailGo, tailRow, tailCol);
			tailClock = tailClock + 1;
			modiGo(tailGo, direction[tailClock]);
		}
		modiGo(headGo, direction[headClock]);
	}

	cout << headClock;
	return 0;
}