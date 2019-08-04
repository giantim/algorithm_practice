#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Word
{
public:
	vector<string> w;
};

Word myWord[26];

int makeWord(Word word)
{
	int size = word.w.size();
	if (size == 1)
		return 1;
	int ret = 0;
	int i = 0;
	while (i < size)
	{
		string s = word.w[i];
		string max = "";
		for (int j = 0; j < size; j++)
		{
			if (j == i)
				continue;
			else
			{
				string comp = word.w[j];
				string temp;
				int k = 0;
				temp.push_back(s[k]);
				do
				{
					k++;
					if (k == s.size())
						break;
					temp.push_back(s[k]);
				} while (s[k] == comp[k]);
				if (temp.size() > max.size())
					max = temp;
			}
		}
		ret += max.size();
		i++;
	}
	return ret;
}

int solution(vector<string> words)
{
	int answer = 0;
	vector<string> v = words;
	sort(v.begin(), v.end());
	int index = 0;
	int i = 0;
	char firstChar = v[0][0];
	while (i < v.size())
	{
		if (firstChar == v[i][0])
		{
			myWord[index].w.push_back(v[i]);
			i++;
		}
		else
		{
			firstChar = v[i][0];
			index++;
		}
	}
	for (i = 0; i <= index; i++)
		answer += makeWord(myWord[i]);

	return answer;
}