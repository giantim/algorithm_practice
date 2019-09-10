#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Chat
{
public:
	string userId;
	string tag; // true = come, false = out

	Chat()
	{
		userId = "";
		tag = "";
	}

	Chat(string userId, string tag)
	{
		this->userId = userId;
		this->tag = tag;
	}
};

class Info
{
public:
	string userId;
	string name;

	Info()
	{
		userId = "";
		name = "";
	}

	Info(string userId, string name)
	{
		this->userId = userId;
		this->name = name;
	}

	void changeName(string name)
	{
		this->name = name;
	}
};

vector<string> solution(vector<string> record)
{
	vector<string> answer;

	map<string, string> m;
	vector<Chat> chat;
	string come = "님이 들어왔습니다.";
	string out = "님이 나갔습니다.";
	for (int i = 0; i < record.size(); i++)
	{
		string s = record[i];
		string command = s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1);
		string userId = s.substr(0, s.find(" "));
		string name;
		if (command == "Enter")
		{
			name = s.substr(s.find(" ") + 1);
			if (m.find(userId) != m.end())
				m.find(userId)->second = name;
			else
				m.insert(make_pair(userId, name));
			chat.push_back(Chat(userId, come));
		}
		else if (command == "Leave")
		{
			chat.push_back(Chat(userId, out));
		}
		else
		{
			name = s.substr(s.find(" ") + 1);
			m.find(userId)->second = name;
		}
	}
	for (int i = 0; i < chat.size(); i++)
		answer.push_back(m.find(chat[i].userId)->second + chat[i].tag);

	return answer;
}

int main()
{
	vector<string> record;

	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	vector<string> answer = solution(record);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	return 0;
}
// Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan