#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& nums)
{
	int leftmin = INT_MAX; //记录前若干天的最小价格
	int ret = 0;           //记录如果当前天卖出可以得到的最大利润
	for (int i = 0; i < nums.size(); ++i)
	{
		leftmin = min(leftmin, nums[i]);
		//当前天的最大利润为：前几天的最大利润和当前天的股价减去最小股价的较大值
		ret = max(ret, nums[i] - leftmin);
	}
	return ret;
}
int maxProfit2(vector<int>& nums)
{
	//下标代表第i天，内容代表前i天的最大利润
	vector<int> dp(nums.size() + 1, 0);
	int leftmin = INT_MAX;
	for (int i = 1; i <= nums.size(); ++i)
	{
		leftmin = min(nums[i - 1], leftmin);
		dp[i] = max(dp[i - 1], nums[i - 1] - leftmin);
	}
	return dp[nums.size()];
}
void test()
{
	vector<int> nums = { 2,5,1,3 };
	cout << maxProfit(nums) << endl;
	cout << maxProfit2(nums) << endl;
}

int main()
{
	test();
	return 0;
}