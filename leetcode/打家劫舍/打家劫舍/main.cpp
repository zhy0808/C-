#include <iostream>
#include <vector>
using namespace std;
//dp数组内容代表在前i家中最多可以偷多少钱
int rob(vector<int>& nums)
{
	if (nums.size() == 1)
		return nums[0];
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); ++i)
	{
		//每次可以选择偷第i家或者不偷第i家
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}
	return dp[nums.size() - 1];
}
void test()
{
	vector<int> nums = { 1,2,3,1 };
	cout << rob(nums) << endl;
}
int main()
{
	test();
	return 0;
}