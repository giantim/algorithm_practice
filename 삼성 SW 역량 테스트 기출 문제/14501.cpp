#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Consult
{
public:
	int time;
	int pay;

	Consult()
	{
		this->time = 0;
		this->pay = 0;
	}

	Consult(int time, int pay)
	{
		this->time = time;
		this->pay = pay;
	}
};

vector<Consult> v;
vector<int> sum;
int add;

void recursiveSum(int index, int oldIndex)
{
	int i;
	for (i = index; i < v.size(); i++)
	{
		if (i + v[i].time <= v.size())
		{
			add = add + v[i].pay;
			recursiveSum(i + v[i].time, i);
		}
	}
	sum.push_back(add);
	add = add - v[oldIndex].pay;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int T, P;
	for (int i = 0; i < N; i++)
	{
		cin >> T >> P;
		v.push_back(Consult(T, P));
	}

	add = 0;
	recursiveSum(0, 0);
	sort(sum.begin(), sum.end());

	cout << sum[sum.size() - 1];
	return 0;
}