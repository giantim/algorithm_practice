#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Info
{
public:
	int index;
	float rate;

	Info()
	{
		index = -1;
		rate = -1;
	}

	Info(int index, float rate)
	{
		this->index = index;
		this->rate = rate;
	}
};

bool compare(const Info& i1, const Info& i2)
{
	return i1.rate > i2.rate;
}

vector<int> solution(int N, vector<int> stages)
{
	vector<int> answer;

	vector<Info> v;
	sort(stages.begin(), stages.end());
	int size = stages.size();
	int i, j;
	int index = 0;
	for (i = 1; i <= N; i++)
	{
		int count = 0;
		for (j = index; j < stages.size(); j++)
		{
			if (stages[j] == i)
				count++;
			else if (stages[j] > i)
			{
				index = j;
				break;
			}
		}
		v.push_back(Info(i, count / (float)size));
		size = size - count;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		answer.push_back(v[i].index);

	return answer;
}

int main()
{
	int N;
	vector<int> stages;
	
	N = 5;
	stages.push_back(2);
	stages.push_back(1);
	stages.push_back(2);
	stages.push_back(6);
	stages.push_back(2);
	stages.push_back(4);
	stages.push_back(3);
	stages.push_back(3);


	/*N = 4;
	stages.push_back(4);
	stages.push_back(4);
	stages.push_back(4);
	stages.push_back(4);
	stages.push_back(4);*/

	vector<int> answer = solution(N, stages);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}
// 5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
// 4	[4,4,4,4,4]	[4,1,2,3]