#include <iostream>
#include <vector>
using namespace std;

int minDistance(string s1, string s2)
{
	//dp[i][j]表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
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
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			//不相同，替换、删除、增加
			else
				dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));

		}
	}
	return dp[s1.size()][s2.size()];
}
void test()
{
	cout << minDistance("horse", "ors") << endl;
}
int main()
{
	test();
	return 0;
}