#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	//dp[i]表示nums数组以nums[i]结尾的连续子数组的最大和
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	int ret = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{

		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		//dp[i]的最大值就是结果
		if (dp[i] > ret)
			ret = dp[i];
	}
	return ret;

}
void test()
{
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << maxSubArray(nums) << endl;
}
int main()
{
	test();
	return 0;
}