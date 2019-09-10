#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[21][21];
vector<int> indexSet;
vector<int> answer;

void calculate()
{

}

class Trie
{
public:
	Trie* next;
	int depth;

	Trie()
	{
		next = new Trie[N];
		fill(next, next + N, nullptr);
		depth = 0;
	}

	Trie(int depth)
	{
		next = new Trie[N];
		fill(next, next + N, nullptr);
		this->depth = depth + 1;
	}

	void make(int num)
	{
		if (this->depth == N / 2)
		{
			calculate();
			indexSet.pop_back();
		}
		else
		{
			for (int i = num; i <= N; i++)
			{
				next = new Trie(this->depth);
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
			board[i][j] = -1;
	}

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}

	sort(answer.begin(), answer.end());
	if (answer[0] < 0)
		cout << -answer[0];
	else
		cout << answer[0];
	return 0;
}