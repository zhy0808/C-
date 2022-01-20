#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n)
{
	vector<int> dp(n + 1);
	dp[2] = 1;//1和0都不能拆分，故不用初始化1和0位置
	for (int i = 3; i <= n; ++i)//计算i可以拆分后乘积的最大值，存放在dp[i]中
	{
		for (int j = 1; j < i; ++j)//拆成j和i-j
		{
			//p[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
			//最大值有两种情况：
			//1.拆分成多个数，用j*dp[i-j]，dp[i-j]就是把i-j拆分成多个数乘积的最大值，j不用再拆，遍历的过程就把所有情况计算过了
			if (dp[i - j] > i - j)
				dp[i] = max(dp[i], dp[i - j] * j);
			//2.拆分成两个数，j*i-j，这种情况适用于不拆比拆了再乘的值大
			else
				dp[i] = max(dp[i], (i - j) * j);
		}
	}
	return dp[n];
}
void test()
{
	cout << integerBreak(10) << endl;
}
int main()
{
	test();
	return 0;
}