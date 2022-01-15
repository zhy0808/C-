#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
	if (n < 2)
		return n;
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
void test()
{
	int ret = fib(19);
	cout << ret << endl;
}

int main()
{
	test();
	return 0;
}