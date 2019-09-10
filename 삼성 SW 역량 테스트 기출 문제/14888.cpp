#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> number;
vector<int> oper;
vector<int> answer;

class Trie
{
public:
	Trie* next[4];
	vector<int> countOper;
	int depth;
	int result;

	Trie()
	{
		fill(next, next + 4, nullptr);
		for (int i = 0; i < 4; i++)
			countOper.push_back(oper[i]);
		depth = 0;
		result = number[depth];
	}

	Trie(vector<int> v, int depth, int tempNumber)
	{
		fill(next, next + 4, nullptr);
		for (int i = 0; i < 4; i++)
			countOper.push_back(v[i]);
		this->depth = depth + 1;
		this->result = tempNumber;
	}

	~Trie()
	{
		for (int i = 0; i < 4; i++)
		{
			if (next[i])
				delete next[i];
		}
	}

	bool checkEmpty()
	{
		for (int i = 0; i < 4; i++)
		{
			if (countOper[i] != 0)
				return false;
		}
		return true;
	}

	int calculate(int index, int num, int depth)
	{
		switch (index)
		{
		case 0:
			return num + number[depth + 1];
		case 1:
			return num - number[depth + 1];
		case 2:
			return num * number[depth + 1];
		case 3:
			return num / number[depth + 1];
		default:
			return 0;
		}
	}

	void make()
	{
		if (!checkEmpty())
		{
			for (int i = 0; i < 4; i++)
			{
				if (countOper[i] != 0)
				{
					vector<int> temp;
					for (int j = 0; j < 4; j++)
					{
						if (i == j)
							temp.push_back(countOper[j] - 1);
						else
							temp.push_back(countOper[j]);
					}
					next[i] = new Trie(temp, depth, calculate(i, result, depth));
					next[i]->make();
				}
			}
		}
		else
			answer.push_back(result);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int A;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		number.push_back(A);
	}
	for (int i = 0; i < 4; i++)
	{
		int op;
		cin >> op;
		oper.push_back(op);
	}

	Trie* root = new Trie();
	root->make();
	sort(answer.begin(), answer.end());

	cout << answer[answer.size() - 1] << endl << answer[0];
	return 0;
}