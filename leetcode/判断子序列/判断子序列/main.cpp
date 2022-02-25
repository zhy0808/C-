#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t)
{
	//dp[i][j]表示s的i-1位置前和t的j-1位置前的公共子序列最大长度
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = 1; j <= t.size(); ++j)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	//如果最大长度等于s字符串的长度，说明s是t的字串
	if (dp[s.size()][t.size()] == s.size())
		return true;
	else
		return false;
}
void test()
{
	cout << isSubsequence("ace", "asdcfgdce") << endl;
}
int main()
{
	test();
	return 0;
}