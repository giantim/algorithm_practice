#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

vector<string> comp1;
vector<string> comp2;

bool isLower(string s)
{
	if ((s[0] >= 'a' && s[0] <= 'z')
		|| (s[1] >= 'a' && s[1] <= 'z'))
		return true;
	return false;
}

string toUpper(string s)
{
	char first = s[0];
	char second = s[1];
	if (first >= 'a' && first <= 'z')
		first -= 32;
	if (second >= 'a' && second <= 'z')
		second -= 32;
	string retString;
	retString.push_back(first);
	retString.push_back(second);
	return retString;
}

void parsing(vector<string>& v, string str)
{
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (isalpha(str[i]) && isalpha(str[i + 1]))
		{
			string s = str.substr(i, 2);
			if (isLower(s))
				v.push_back(toUpper(s));
			else
				v.push_back(s);
		}
	}
}

int solution(string str1, string str2)
{
	int answer = 0;
	int i;

	parsing(comp1, str1);
	parsing(comp2, str2);
	
	int comp1Size = comp1.size();
	int comp2Size = comp2.size();

	if (comp1Size == 0 && comp2Size == 0)
		return 65536;
	else if (comp1Size == 0 || comp2Size == 0)
		return 0;
	else
	{
		int inter = 0;
		for (i = 0; i < comp1Size; i++)
		{
			int j = 0;
			while (j < comp2.size())
			{
				if (comp1[i] == comp2[j])
				{
					inter++;
					comp2.erase(comp2.begin() + j);
					break;
				}
				j++;
			}
		}
		int uni = comp1Size + comp2Size - inter;
		answer = ((double)inter / uni) * 65536;
		return answer;
	}
}

int main()
{
	string str1, str2;

	/*str1 = "FRANCE";
	str2 = "french";*/

	/*str1 = "handshake";
	str2 = "shake hands";*/

	/*str1 = "aa1+aa2";
	str2 = "AAAA12";*/

	str1 = "E=M*C^2";
	str2 = "e=m*c^2";

	cout << solution(str1, str2);

	return 0;
}