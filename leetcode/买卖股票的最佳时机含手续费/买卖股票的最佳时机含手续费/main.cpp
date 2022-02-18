#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& nums, int fee)
{
	if (nums.size() == 0)
		return 0;
	vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
	//每次买入股票时扣除手续费
	dp[0][1] = -nums[0] - fee;
	for (int i = 1; i < nums.size(); ++i)
	{
		//未持有股票：昨天就未持有或昨天持有今天卖了
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
		//持有股票：昨天就持有或昨天未持有今天买入
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - nums[i] - fee);
	}
	return dp[nums.size() - 1][0];
}
void test()
{
	vector<int> nums = { 1, 3, 2, 8, 4, 9 };
	cout << maxProfit(nums, 2) << endl;
}
int main()
{
	test();
	return 0;
}