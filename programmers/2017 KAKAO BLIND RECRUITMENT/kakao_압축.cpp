#include <string>
#include <vector>

using namespace std;

vector<string> dictionary;

void initDic(vector<string>& v)
{
	for (int i = 0; i < 26; i++)
	{
		string s;
		char c = i + 'A';
		s.push_back(c);
		v.push_back(s);
	}
}

vector<int> solution(string msg)
{
	vector<int> answer;

	string message = msg;
	int msgSize = message.size();
	initDic(dictionary);
	int index = 0;
	int maxSize = 1;
	while (index < msgSize)
	{
		bool find = false;
		int dicIndex = 0;
		int tempSize = maxSize + 1;
		string save;
		do
		{
			string temp;
			int i;
			for (i = index; i < tempSize + index; i++)
			{
				temp.push_back(message[i]);
				if (i == message.size() - 1)
					break;
			}
			if (temp.size() > 1)
				i = 26;
			else
				i = 0;
			for (; i < dictionary.size(); i++)
			{
				if (dictionary[i] == temp)
				{
					find = true;
					dicIndex = i;
					break;
				}
			}
			if (find == false)
				save = temp;
			tempSize--;
		} while (find == false && tempSize != 0);
		answer.push_back(dicIndex + 1);;
		index += ++tempSize;
		if (save != "")
		{
			dictionary.push_back(save);
			maxSize = maxSize > save.size() ? maxSize : save.size();
		}
	}

	return answer;
}