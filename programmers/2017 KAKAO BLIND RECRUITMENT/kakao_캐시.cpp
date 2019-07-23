#include <string>
#include <vector>

using namespace std;

string toUpper(string s)
{
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			str.push_back(s[i] - 32);
		else
			str.push_back(s[i]);
	}
	return str;
}

class Cache
{
public:
	string cityName;
	int clock;

	Cache(string s)
	{
		this->cityName = s;
		this->clock = 0;
	}

	void initClock()
	{
		this->clock = 0;
	}

	void clockUp()
	{
		this->clock += 1;
	}

	void modiCityName(string s)
	{
		this->cityName = s;
	}
};

void clockUp(vector<Cache>& v)
{
	for (int i = 0; i < v.size(); i++)
		v[i].clockUp();
}

int retMaxIndex(vector<Cache> v)
{
	int index = 0;
	int max = v[0].clock;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].clock >= max)
		{
			max = v[i].clock;
			index = i;
		}
	}
	return index;
}

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;

	if (cacheSize == 0)
		answer = 5 * cities.size();
	else
	{
		vector<Cache> v;
		v.push_back(Cache(toUpper(cities[0])));
		answer = 5;
		int i, j;
		for (i = 1; i < cities.size(); i++)
		{
			clockUp(v);
			string city = toUpper(cities[i]);
			for (j = 0; j < v.size(); j++)
			{
				if (v[j].cityName == city)
				{
					v[j].clock = 0;
					answer += 1;
					break;
				}
			}
			if (j == v.size())
			{
				if (v.size() < cacheSize)
					v.push_back(Cache(city));
				else
				{
					int index = retMaxIndex(v);
					v[index].modiCityName(city);
					v[index].initClock();
				}
				answer += 5;
			}
		}
	}

	return answer;
}