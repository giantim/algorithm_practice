#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isHashTag(char c)
{
	if (c == 'C' || c == 'D' || c == 'F' || c == 'G' || c == 'A')
		return true;
	return false;
}

string convertString(string s)
{
	string convString;
	for (int i = 0; i < s.length(); i++)
	{
		if (isHashTag(s[i]))
		{
			if (i + 1 < s.length() && s[i + 1] == '#')
			{
				convString.push_back(s[i] + ' ');
				i++;
			}
			else
				convString.push_back(s[i]);
		}
		else
			convString.push_back(s[i]);
	}
	return convString;
}

class Time
{
public:
	int hour;
	int minute;

	Time()
	{
		this->hour = 0;
		this->minute = 0;
	}

	void setTime(int hour, int minute)
	{
		this->hour = hour;
		this->minute = minute;
	}
};

class Music
{
public:
	Time startTime;
	Time endTime;
	string musicName;
	string info;
	int playTime;
	string melody = "";

	void initMusic(Time startTime, Time endTime, string musicName, string info)
	{
		this->startTime = startTime;
		this->endTime = endTime;
		this->musicName = musicName;
		this->info = info;
	}

	void setPlayTime()
	{
		int minute = this->endTime.minute - this->startTime.minute;
		int hour = this->endTime.hour - this->startTime.hour;
		if (minute < 0)
		{
			minute += 60;
			hour--;
		}
		this->playTime = (60 * hour) + minute;
	}

	void setMelody()
	{
		int length = this->info.length();
		int i = 0;
		int quo = this->playTime / length;
		int remain = this->playTime % length;
		for (i = 0; i < quo; i++)
			this->melody += this->info;
		for (i = 0; i < remain; i++)
			this->melody.push_back(this->info[i]);
	}

	bool checkMelody(string m)
	{
		for (int i = 0; i < this->melody.length(); i++)
		{
			int count = 0;
			if (m[0] == this->melody[i])
			{
				for (int j = 0; j < m.length(); j++)
				{
					if (m[j] == this->melody[i + j])
						count++;
					else
						break;
				}
				if (count == m.length())
					return true;
			}
		}
		return false;
	}
};

Music initMusicInfo(string musicinfo, int index)
{
	Music myMusic;
	string s = musicinfo;
	Time startTime;
	Time endTime;
	int hour;
	int minute;
	string tempString = s.substr(0, s.find(","));
	string startHour = tempString.substr(0, tempString.find(":"));
	string startMinute = tempString.substr(tempString.find(":") + 1);
	hour = atoi(startHour.c_str());
	minute = atoi(startMinute.c_str());
	startTime.setTime(hour, minute);
	s = s.substr(s.find(",") + 1);
	tempString = s.substr(0, s.find(","));
	string endHour = tempString.substr(0, tempString.find(":"));
	string endMinute = tempString.substr(tempString.find(":") + 1);
	hour = atoi(endHour.c_str());
	minute = atoi(endMinute.c_str());
	endTime.setTime(hour, minute);
	s = s.substr(s.find(",") + 1);
	string musicName = s.substr(0, s.find(","));
	string info = convertString(s.substr(s.find(",") + 1));

	myMusic.initMusic(startTime, endTime, musicName, info);
	return myMusic;
}

int findMaxPlayTime(vector<Music> v)
{
	int index = 0;
	int max = v[0].playTime;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].playTime > max)
		{
			max = v[i].playTime;
			index = i;
		}
	}
	return index;
}

string solution(string m, vector<string> musicinfos)
{
	string answer = "";

	string melody = convertString(m);
	int size = musicinfos.size();
	vector<Music> v;
	for (int i = 0; i < size; i++)
	{
		Music myMusic = initMusicInfo(musicinfos[i], i);
		myMusic.setPlayTime();
		myMusic.setMelody();
		if (myMusic.checkMelody(melody))
			v.push_back(myMusic);
	}	
	if (v.size() == 0)
		answer = "`(None)`";
	else
		answer = v[findMaxPlayTime(v)].musicName;

	return answer;
}

int main()
{
	string m;
	vector<string> musicinfos;
	
	m = "ABCDEFG";
	musicinfos.push_back("11:59,12:14,HELLO,CDEFGAB");
	musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

	/*m = "CC#BCC#BCC#BCC#B";
	musicinfos.push_back("03:00,03:30,FOO,CC#B");
	musicinfos.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");*/

	/*m = "ABC";
	musicinfos.push_back("12:00,12:14,HELLO,C#DEFGAB");
	musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");*/

	cout << solution(m, musicinfos);

	return 0;
}

//ABCDEFG[12:00, 12 : 14, HELLO, CDEFGAB, 13 : 00, 13 : 05, WORLD, ABCDEF]
//CC#BCC#BCC#BCC#B[03:00, 03 : 30, FOO, CC#B, 04:00, 04 : 08, BAR, CC#BCC#BCC#B]
//ABC	[12:00,12:14,HELLO,C#DEFGAB, 13:00,13:05,WORLD,ABCDEF]