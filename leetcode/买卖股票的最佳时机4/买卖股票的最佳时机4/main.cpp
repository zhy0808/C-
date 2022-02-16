#include <iostream>
#include <vector>
using namespace std;
int maxProfit(int k, vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	vector<vector<int>> dp(nums.size(), vector<int>(2 * k + 1, 0));
	//第0天不管第几次卖出，当前的最大利润都为负第一天的股价
	for (int j = 1; j < 2 * k + 1; j += 2)
	{
		dp[0][j] = -nums[0];
	}
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = 0; j < 2 * k - 1; j += 2)
		{
			//第i天第（j+1）%2次持有股票的最大利润
			dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - nums[i]);
			//第i天第（j+2）/2次不持有股票的最大利润
			dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + nums[i]);
		}
	}
	return dp[nums.size() - 1][2 * k];
}
void test()
{
	vector<int> nums = { 3,2,6,5,0,3 };
	cout << maxProfit(2, nums) << endl;
}
int main()
{
	test();
	return 0;
}