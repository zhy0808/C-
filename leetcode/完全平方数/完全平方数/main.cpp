#include <iostream>
#include <vector>
using namespace std;
//dp数组下标代表要组成的数，内容代表要组成该数至少需要几个完全平方数
int numSquares(int n)
{
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	//由于要求的是最小需要的个数，所以先遍历物品（组合）还是先遍历背包（排列）对该题没有影响
	for (int i = 1; i * i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (j >= i * i)
				dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}
	return dp[n];
}
void test()
{
	cout << numSquares(10) << endl;
}
int main()
{

	test();
	return 0;
}