#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Food
{
public:
	int index;
	unsigned int length;

	Food()
	{
		index = length = 0;
	}

	Food(int index, int length)
	{
		this->index = index;
		this->length = length;
	}
};

int solution(vector<int> food_times, long long k)
{
	int answer = 0;

	queue<Food> fq;
	for (int i = 0; i < food_times.size(); ++i)
		fq.push(Food(i + 1, food_times[i]));
	for (unsigned int i = 0; i < k && !fq.empty(); ++i)
	{
		Food temp = fq.front();
		fq.pop();
		if (temp.length - 1 != 0)
		{
			temp.length = temp.length - 1;
			fq.push(temp);
		}
	}
	if (fq.empty())
		answer = -1;
	else
		answer = fq.front().index;

	return answer;
}

int main()
{

}