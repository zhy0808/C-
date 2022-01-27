#include <iostream>
#include <vector>
using namespace std;
//背包容量为m个0，n个1，每个字符含zeroNum个0，oneNum个1
//将若干个字符装进背包中，求最多可以装多少个字符
//背包容量为m个0，n个1，有若干个物品，每个物品重量为zero个0，one个1，价值（个数）为1
int findMaxForm(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	//在前k个字符串中选若干个放入背包的最大数量为dp[i][j]
	for (string str : strs)
	{
		//记录每个字符串含有0、1的个数，即字符串的重量
		int zero = 0, one = 0;
		for (char c : str)
		{
			if (c == '0')
				zero++;
			else
				one++;
		}
		//
		for (int i = m; i >= zero; --i)
		{
			for (int j = n; j >= one; --j)
			{
				dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
			}
		}
	}
	return dp[m][n];
}
void test()
{
	vector<string> strs = { "10", "0001", "111001", "1", "0" };
	cout << findMaxForm(strs, 5, 3) << endl;
}
int main()
{
	test();
	return 0;
}