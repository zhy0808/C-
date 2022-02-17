#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	//状态0：当前处于持有股票状态
	//状态1：今天卖出股票
	//状态2：两天前卖出股票,且度过了冷冻期,处于卖出股票状态
	//状态3：当前处于冷冻期
	vector<vector<int>> dp(nums.size(), vector<int>(4, 0));
	dp[0][0] = -nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]) - nums[i]);
		dp[i][1] = dp[i - 1][0] + nums[i];
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);
		dp[i][3] = dp[i - 1][1];
	}
	int n = nums.size() - 1;
	return max(dp[n][1], max(dp[n][2], dp[n][3]));
}
void test()
{
	vector<int> nums = { 1,2,3,0,2 };
	cout << maxProfit(nums) << endl;
}
int main()
{
	test();
	return 0;
}