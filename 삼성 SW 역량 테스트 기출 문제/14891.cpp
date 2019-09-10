#include <iostream>
#include <vector>

using namespace std;

int pow(int original, int number, int index)
{
	if (index == 0)
		return 1;
	else if (index == 1)
		return number;
	else
		return pow(original, original * number, index - 1);
}

class Gear
{
public:
	vector<int> pole;
	int index;
	
	Gear()
	{
		this->index = 0;
	}

	void setIndex(int index)
	{
		this->index = index;
	}

	void rotate(int direction)
	{
		if (direction == 1)
			rightShift();
		else
			leftShift();
	}

	void leftShift()
	{
		vector<int> temp = this->pole;
		for (int i = 0; i < 8; i++)
			this->pole[i] = temp[(i + 9) % 8];
	}

	void rightShift()
	{
		vector<int> temp = this->pole;
		for (int i = 0; i < 8; i++)
			this->pole[(i + 9) % 8] = temp[i];
	}

	int calculateScore()
	{
		if (this->pole[0] == 0)
			return 0;
		else
			return pow(2, 2, this->index);
	}
};

void checkPole(Gear g[4], vector<int>& status)
{
	if (g[0].pole[2] == g[1].pole[6])
		status.push_back(0);
	else
		status.push_back(1);

	if (g[1].pole[2] == g[2].pole[6])
		status.push_back(0);
	else
		status.push_back(1);

	if (g[2].pole[2] == g[3].pole[6])
		status.push_back(0);
	else
		status.push_back(1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Gear gear[4];
	for (int i = 0; i < 4; i++)
	{
		gear[i].setIndex(i);
		string number;
		cin >> number;
		for (int j = 0; j < 8; j++)
			gear[i].pole.push_back(number[j] - 48);
	}

	int K;
	cin >> K;

	int index;
	int direction;
	vector<int> status;

	for (int i = 0; i < K; i++)
	{
		cin >> index >> direction;
		checkPole(gear, status);
		gear[index - 1].rotate(direction);
		if (index == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (status[j] == 0)
					break;
				else
				{
					direction = direction * -1;
					gear[j + 1].rotate(direction);
				}
			}
		}
		else if (index == 2)
		{
			if (status[0] == 1)
				gear[0].rotate(direction * -1);
			for (int j = 1; j < 3; j++)
			{
				if (status[j] == 0)
					break;
				else
				{
					direction = direction * -1;
					gear[j + 1].rotate(direction);
				}
			}
		}
		else if (index == 3)
		{
			if (status[2] == 1)
				gear[3].rotate(direction * -1);
			for (int j = 1; j >= 0; j--)
			{
				if (status[j] == 0)
					break;
				else
				{
					direction = direction * -1;
					gear[j].rotate(direction);
				}
			}
		}
		else
		{
			for (int j = 2; j >= 0; j--)
			{
				if (status[j] == 0)
					break;
				else
				{
					direction = direction * -1;
					gear[j + 1].rotate(direction);
				}
			}
		}
		status.clear();
	}

	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += gear[i].calculateScore();

	cout << sum;
	return 0;
}