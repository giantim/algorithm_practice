#include <string>

using namespace std;

string line[3];
int score[3];

int power(int num, char s)
{
	if (s == 'S')
		return num;
	else if (s == 'D')
		return num * num;
	else if (s == 'T')
		return num * num * num;
}

int solution(string dartResult)
{
	int answer = 0;
	int size = dartResult.size();
	int index = 0;
	int start = 0;
	int count = 0;

	for (int j = 0; j < size; j++)
	{
		if (dartResult[j] >= 48 && dartResult[j] <= 57)
			count++;
		else
		{
			if (dartResult[j + 1] == '*' || dartResult[j + 1] == '#')
			{
				line[index++] = dartResult.substr(start, count + 2);
				start += count + 2;
				count = 0;
				j++;
			}
			else
			{
				line[index++] = dartResult.substr(start, count + 1);
				start += count + 1;
				count = 0;
			}
		}
	}
	for (int j = 0; j < 3; j++)
	{
		int temp = 0;
		if (line[j][1] == '0')
		{
			temp = stoi(line[j].substr(0, 2));
			index = 2;
		}
		else
		{
			temp = line[j][0] - 48;
			index = 1;
		}
		if (line[j][index + 1] == '*' || line[j][index + 1] == '#')
		{
			score[j] = power(temp, line[j][index]);
			if (j >= 1)
			{
				if (line[j][index + 1] == '*')
				{
					score[j] *= 2;
					score[j - 1] *= 2;
				}
				else if (line[j][index + 1] == '#')
					score[j] *= -1;
			}
			else
			{
				if (line[j][index + 1] == '*')
					score[j] *= 2;
				else
					score[j] *= -1;
			}
		}
		else
			score[j] = power(temp, line[j][index]);
	}
	for (int j = 0; j < 3; j++)
		answer += score[j];

	return answer;
}