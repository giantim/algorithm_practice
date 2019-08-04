#include <string>
#include <vector>

using namespace std;

char overTen(int x)
{
	switch (x)
	{
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		default:
			return ' ';
	}
}

string convert(int n, int num)
{
	if (num == 0)
		return "0";
	string s = "";
	int remainder;
	char c;
	while (num > 0)
	{
		remainder = num % n;
		if (remainder >= 10)
			s.push_back(overTen(remainder));
		else
		{
			c = remainder + '0';
			s.push_back(c);
		}
		num /= n;
	}
	string convNum = "";
	for (int i = s.size() - 1; i >= 0; i--)
		convNum.push_back(s[i]);
	return convNum;
}

string solution(int n, int t, int m, int p)
{
	string answer = "";

	int punc = n;
	int prepare = t;
	int participants = m;
	int tube = p;
	int turn = tube % participants;

	int number = 0;
	int preQuotient = -1;
	int index = 1;
	while (answer.size() < prepare)
	{
		string convNum = convert(punc, number);
		int size = convNum.size();
		for (int i = 0; i < size; i++)
		{
			if (index % participants == turn)
			{
				answer.push_back(convNum[i]);
				if (answer.size() == prepare)
					return answer;
			}
			index++;
		}
		number++;
	}

	return answer;
}