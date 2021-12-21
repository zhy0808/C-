#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool huiwen(string s, int left, int right)
{
	while (left < right)
	{
		if (s[left++] != s[right--])
			return false;
	}
	return true;
}
void find(string s, vector<vector<string>>& ret, vector<string>& path, int begin)
{
	if (begin >= s.size())
	{
		ret.push_back(path);
		return;
	}
	for (int i = begin; i < s.size(); i++)
	{
		if (huiwen(s, begin, i))
		{
			path.push_back(s.substr(begin, i - begin + 1));
			find(s, ret, path, i + 1);
			path.pop_back();
		}
		else
			continue;
	}
}
vector<vector<string>> partitor(string s)
{
	vector<vector<string>> ret;
	vector<string> path;
	find(s, ret, path, 0);
	return ret;
}


void test()
{
	vector<vector<string>> ret;
	ret = partitor("aab");
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	test();
	return 0;
}