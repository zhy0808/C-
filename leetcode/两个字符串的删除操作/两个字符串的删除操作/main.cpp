#include <iostream>
#include <vector>
using namespace std;
int minDistance(string s1, string s2)
{
	//dp[i][j]表示s1中以i-1为结尾的字符串和s2中以j-1为结尾的字符串要达到相等需要删除的最少字符数
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	//当s1为空串或者s2为空串时，另一个字符串要达到相等就需要删除所有字符
	for (int i = 0; i <= s1.size(); ++i)
	{
		dp[i][0] = i;
	}
	for (int j = 0; j <= s2.size(); ++j)
	{
		dp[0][j] = j;
	}
	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			//如果s1[i - 1]与s[j - 1]相同时，不要需要删除字符
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			//如果不相同时，有三种情况：删除s1的第i-1个字符；删除s2的第j-1个字符；同时删除两个字符
			else
				dp[i][j] = min(dp[i - 1][j - 1] + 2, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
		}
	}
	return dp[s1.size()][s2.size()];
}
void test()
{
	cout << minDistance("sea", "eat") << endl;
}
int main()
{
	test();
	return 0;
}