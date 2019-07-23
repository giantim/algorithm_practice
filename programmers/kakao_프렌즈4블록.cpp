#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Square 
{
public:
	char name;
	bool check;

	void setInit(char c)
	{
		this->name = c;
		this->check = false;
	}

	void modiCheck(int& count)
	{
		if (!this->check)
		{
			this->check = true;
			count++;
		}
	}

	void modiName()
	{
		if (this->check)
		{
			this->name = ' ';
			this->check = false;
		}
	}

	char print()
	{
		return this->name;
	}
};

void nameSwap(Square& s1, Square& s2)
{
	char name = s1.name;
	s1.name = s2.name;
	s2.name = name;
}

Square arr[30][30];

int solution(int m, int n, vector<string> board)
{
	int answer = 0;
	int i, j;
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			arr[i][j].setInit(board[i][j]);
	}
	
	bool find;
	do
	{
		find = false;
		for (i = 0; i < m - 1; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				char compName = arr[i][j].name;
				if (compName != ' ')
				{
					if (arr[i][j + 1].name == compName && arr[i + 1][j].name == compName
						&& arr[i + 1][j + 1].name == compName)
					{
						arr[i][j].modiCheck(answer);
						arr[i][j + 1].modiCheck(answer);
						arr[i + 1][j].modiCheck(answer);
						arr[i + 1][j + 1].modiCheck(answer);
						find = true;
					}
				}
			}			
		}
		if (find)
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
					arr[i][j].modiName();
			}
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (arr[i][j].name == ' ')
					{
						int index = i;
						while (index >= 1)
						{
							if (arr[index - 1][j].name == ' ')
								break;
							nameSwap(arr[index][j], arr[index - 1][j]);
							index--;
						}
					}
				}
			}
		}
	} while (find);

	return answer;
}

int main()
{
	int m, n;
	vector<string> board;

	/*m = 4;
	n = 5;
	board.push_back("CCBDE");
	board.push_back("AAADE");
	board.push_back("AAABF");
	board.push_back("CCBBF");*/

	m = 6;
	n = 6;
	board.push_back("TTTANT");
	board.push_back("RRFACC");
	board.push_back("RRRFCC");
	board.push_back("TRRRAA");
	board.push_back("TTMMMF");
	board.push_back("TMMTTF");

	cout << solution(m, n, board);
	return 0;
}