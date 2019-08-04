#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Time
{
public:
	int hour;
	int minute;
	int* crewIndex;
	int size;

	void initCrewIndex(int m)
	{
		if (m > 0)
		{
			this->crewIndex = new int[m];
			this->size = m;
		}
		else
			this->crewIndex = NULL;
	}

	void setCrewIndex(int index)
	{
		for (int i = this->size - 1; i >= 0; i--)
			crewIndex[i] = index-- - 1;
	}

	int getEmptySeat(int m)
	{
		return m - this->size;
	}

	int getLastCrewInex()
	{
		return this->crewIndex[this->size - 1];
	}

	bool operator <= (const Time& t) const
	{
		if (this->hour == t.hour)
			return this->minute <= t.minute;
		return this->hour < t.hour;
	}
};

bool operator < (const Time& t1, const Time& t2)
{
	if (t1.hour == t2.hour)
		return t1.minute < t2.minute;
	return t1.hour < t2.hour;
}

Time crew[2000];
Time arrival[10];

void initTime(string s, int index)
{
	int hour = atoi(s.substr(0, s.find(':')).c_str());
	int minute = atoi(s.substr(s.find(':') + 1, 2).c_str());
	
	crew[index].hour = hour;
	crew[index].minute = minute;
}

void initArrival(int n, int t)
{
	arrival[0].hour = 9;
	arrival[0].minute = 0;
	for (int i = 1; i < n; i++)
	{
		arrival[i].minute = arrival[i - 1].minute + t;
		if (arrival[i].minute >= 60)
		{
			arrival[i].hour = arrival[i - 1].hour + 1;
			arrival[i].minute -= 60;
		}
		else
			arrival[i].hour = arrival[i - 1].hour;
	}
}

string solution(int n, int t, int m, vector<string> timetable)
{
	string answer = "";

	int i;
	int size = timetable.size();
	for (i = 0; i < size; i++)
		initTime(timetable[i], i);
	sort(crew, crew + size);
	initArrival(n, t);
	int crewIndex = 0;
	for (i = 0; i < n; i++)
	{
		int count = 0;
		Time stand = arrival[i];
		while (crewIndex < size)
		{
			if (crew[crewIndex] <= stand)
			{
				crewIndex++;
				count++;
				if (count == m)
					break;
			}
			else
				break;
		}
		arrival[i].initCrewIndex(count);
		arrival[i].setCrewIndex(crewIndex);
	}
	int emptySeat = arrival[n - 1].getEmptySeat(m);
	if (emptySeat >= 1)
	{
		int hour = arrival[n - 1].hour;
		int minute = arrival[n - 1].minute;
		if (hour < 10)
			answer += to_string(0);
		answer += to_string(hour) + ":";
		if (minute < 10)
			answer += to_string(0);
		answer += to_string(minute);
	}
	else if (emptySeat == 0)
	{
		crewIndex = arrival[n - 1].getLastCrewInex();
		int hour = crew[crewIndex].hour;
		int minute = crew[crewIndex].minute;
		if (minute == 0)
		{
			minute = 59;
			hour -= 1;
		}
		else
			minute--;
		if (hour < 10)
			answer += to_string(0);
		answer += to_string(hour) + ":";
		if (minute < 10)
			answer += to_string(0);
		answer += to_string(minute);
	}

	return answer;
}

int main()
{
	int n, t, m;
	vector<string> timetable;
	
	/*n = 2;
	t = 10;
	m = 2;
	timetable.push_back("09:10");
	timetable.push_back("09:09");
	timetable.push_back("08:00");*/

	/*n = 10;
	t = 60;
	m = 45;
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");
	timetable.push_back("23:59");*/

	/*n = 1;
	t = 1;
	m = 5;
	timetable.push_back("08:00");
	timetable.push_back("08:01");
	timetable.push_back("08:02");
	timetable.push_back("08:03");*/

	n = 2;
	t = 1;
	m = 2;
	timetable.push_back("09:00");
	timetable.push_back("09:00");
	timetable.push_back("09:00");
	timetable.push_back("09:00");

	cout << solution(n, t, m, timetable);
	return 0;
}

//1	1 5[08:00, 08:01, 08:02, 08:03]	09:00
//2	10 2[09:10, 09:09, 08:00] 09:09
//2	1 2[09:00, 09:00, 09:00, 09:00]	08:59
//1	1 5[00:01, 00:01, 00:01, 00:01, 00:01] 00:00
//1	1 1[23:59]	09:00
//10 60	45[23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59]	18:00