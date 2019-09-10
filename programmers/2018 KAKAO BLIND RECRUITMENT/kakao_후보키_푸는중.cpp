#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> relation)
{
	int answer = 0;

	


	return answer;
}

int main()
{
	vector<vector<string>> relation;
	vector<string> v;
	
	v.push_back("100");
	v.push_back("ryan");
	v.push_back("music");
	v.push_back("2");
	relation.push_back(v);
	v.clear();

	v.push_back("200");
	v.push_back("apeach");
	v.push_back("math");
	v.push_back("2");
	relation.push_back(v);
	v.clear();

	v.push_back("300");
	v.push_back("tube");
	v.push_back("computer");
	v.push_back("3");
	relation.push_back(v);
	v.clear();

	v.push_back("400");
	v.push_back("con");
	v.push_back("computer");
	v.push_back("4");
	relation.push_back(v);
	v.clear();

	v.push_back("500");
	v.push_back("muzi");
	v.push_back("music");
	v.push_back("3");
	relation.push_back(v);
	v.clear();

	v.push_back("600");
	v.push_back("apeach");
	v.push_back("music");
	v.push_back("2");
	relation.push_back(v);
	v.clear();

	cout << solution(relation);

	return 0;
}