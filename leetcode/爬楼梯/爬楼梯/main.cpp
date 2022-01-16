#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n)
{
	if (n <= 2)
	{
		return n;
	}
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
int climbStairs2(int n)
{
	if (n <= 2)
		return n;
	vector<int> dp(3);
	dp[1] = 1;
	dp[2] = 2;
	int tmp;
	for (int i = 3; i <= n; ++i)
	{
		tmp = dp[2];
		dp[2] = dp[1] + tmp;
		dp[1] = tmp;
	}
	return dp[2];
}

void test()
{
	cout << climbStairs(20) << endl;

}
int main()
{
	test();
	return 0;
}