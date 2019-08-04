#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class File
{
public:
	string original;
	string head;
	int number;

	void initFile(string original, string head, int number)
	{
		this->original = original;
		this->head = head;
		this->number = number;
	}
};

File f[1000];

bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool isLower(char c)
{
	if (c >= 'a' && c <= 'z')
		return true;
	return false;
}

void toUpper(string& s)
{
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		if (isLower(s[i]))
			s[i] -= 32;
	}
}

void parsing(string s, int index)
{
	int length = s.length();
	int i;
	string head;
	string tempNumber;
	for (i = 0; i < length; i++)
	{
		if (isNumber(s[i]))
			break;
		else 
			head.push_back(s[i]);
	}
	toUpper(head);
	int stand = i + 5;
	for (; i < stand; i++)
	{
		if (isNumber(s[i]))
			tempNumber.push_back(s[i]);
		else
			break;
	}
	int number = atoi(tempNumber.c_str());
	f[index].initFile(s, head, number);
}

bool compare(const File& f1, const File& f2)
{
	if (f1.head == f2.head)
		return f1.number < f2.number;
	return f1.head < f2.head;
}

vector<string> solution(vector<string> files)
{
	vector<string> answer;

	int size = files.size();
	for (int i = 0; i < size; i++)
		parsing(files[i], i);
	stable_sort(f, f + size, compare);
	for (int i = 0; i < size; i++)
		answer.push_back(f[i].original);

	return answer;
}