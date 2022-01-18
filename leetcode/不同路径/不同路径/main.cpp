#include <iostream>
#include <vector>
using namespace std;
//dp数组下标表示网格的对应位置，数组中的内容表示走到对应下标位置一共有多少条路径
int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
		dp[i][0] = 1;
	for (int j = 0; j < n; ++j)
		dp[0][j] = 1;
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
	}
	return dp[m - 1][n - 1];
}

void test()
{
	cout << uniquePaths(3, 7) << endl;
}

int main()
{
	test();
	return 0;
}