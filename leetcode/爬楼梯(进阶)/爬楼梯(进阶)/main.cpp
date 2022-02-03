#include <iostream>
#include <vector>
using namespace std;
//一步一个台阶，两个台阶，三个台阶,直到 n个台阶。问有多少种不同的方法可以爬到楼顶呢？
//台阶总数量为背包容量，每次可以上的阶数为物品重量，求放满背包有多少种方法

int climbStairs(int n)
{
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= j; ++i)
		{
			dp[j] += dp[j - i];
		}
	}
	return dp[n];
}
void test()
{
	cout << climbStairs(3) << endl;
}
int main()
{
	test();
	return 0;
}