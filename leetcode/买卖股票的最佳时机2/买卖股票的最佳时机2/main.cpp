#include <iostream>
#include <vector>
using namespace std;
//贪心
int maxProfit(vector<int>& nums)
{
	int ret = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		ret += max(0, nums[i] - nums[i - 1]);
	}
	return ret;
}
//动态规划
int maxProfit2(vector<int>& nums)
{
	vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = -nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		//第i天不持有股票的最大利润，取前一天不持有股票的最大利润和前一天持有股票今天卖出股票的更大值
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - nums[i]);
	}
	return dp[nums.size() - 1][0];
}
void test()
{
	vector<int> nums = { 7,1,5,3,6,4 };
	cout << maxProfit(nums) << endl;
	cout << maxProfit2(nums) << endl;
}
int main()
{
	test();
	return 0;
}