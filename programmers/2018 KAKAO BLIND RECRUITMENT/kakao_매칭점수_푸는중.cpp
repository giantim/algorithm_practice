#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Info
{
public:
	string pageName;
	string body;
	vector<string> link;
	int basicScore;

	Info()
	{
		pageName = "";
		body = "";
	}

	Info(string pageName, string body, vector<string> link, int basicScore)
	{
		this->pageName = pageName;
		this->body = body;
		this->link = link;
		this->basicScore = basicScore;
	}
};

string parsePageName(string page)
{
	string s = page;
	s = s.substr(s.find("<head>") + 6, s.find("</head>") - (s.find("<head>") + 6));
	string name;
	while (s.find("<meta") != string::npos)
	{
		string temp = s.substr(s.find("<meta"), (s.find(">") + 1) - s.find("<meta"));
		if (temp.find("https://") != string::npos)
		{
			int index = temp.find("https://");
			while (temp[index] != '"')
			{
				name.push_back(temp[index]);
				index = index + 1;
			}
			break;
		}
		s = s.substr(s.find(">") + 1);
	}
	return name;
}

void parseBodyAndLink(string page, string& body, vector<string>& link)
{
	string s = page;
	s = s.substr(s.find("<body>") + 6, s.find("</body>") - (s.find("<body>\n") + 6));
	body = s;
	while (s.find("<a href") != string::npos)
	{
		s = s.substr(s.find("<a href"));
		string linkName = s.substr(s.find("<a href") + 9, s.find("\">") - (s.find("<a href") + 9));
		link.push_back(linkName);
		s = s.substr(s.find("</a>") + 4);
	}
}

bool isAlpha(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

void toLower(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isAlpha(s[i]) == true)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] + 32;
		}
	}
}

int search(string word, string body)
{
	int count = 0;
	string s = body;
	toLower(s);
	string searchWord = word;
	toLower(searchWord);
	int wordLength = searchWord.length();
	while (s.find(searchWord) != string::npos)
	{
		s = s.substr(s.find(searchWord));
		if (isAlpha(s[wordLength]) == false)
			count = count + 1;
		s = s.substr(s.find(searchWord) + wordLength + 1);
	}
	return count;
}

int solution(string word, vector<string> pages)
{
	int answer = 0;

	vector<Info> info;
	map<string, float> outScore;
	map<string, float> totalScore;
	for (int i = 0; i < pages.size(); i++)
	{
		string pageName = parsePageName(pages[i]);
		string body = "";
		vector<string> link;
		parseBodyAndLink(pages[i], body, link);
		int basicScore = search(word, body);
		info.push_back(Info(pageName, body, link, basicScore));
		if (link.size() != 0)
			outScore.insert(make_pair(pageName, basicScore / (float)link.size()));
		else
			outScore.insert(make_pair(pageName, 0));
		totalScore.insert(make_pair(pageName, (float)basicScore));
	}
	for (int i = 0; i < info.size(); i++)
	{
		for (int j = 0; j < info[i].link.size(); j++)
		{
			if (outScore.find(info[i].link[j]) != outScore.end())
				totalScore.find(info[i].link[j])->second += outScore.find(info[i].pageName)->second;
		}
	}
	vector<float> score;
	for (auto i = totalScore.begin(); i != totalScore.end(); i++)
		score.push_back(i->second);
	float max = score[0];
	for (int i = 1; i < score.size(); i++)
	{
		if (score[i] > max)
		{
			answer = i;
			max = score[i];
		}
	}
	return answer;
}

int main()
{
	string word;
	vector<string> pages;

	word = "blind";
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>");

	/*word = "Muzi";
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>");
	pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>");*/

	cout << solution(word, pages);

	return 0;
}