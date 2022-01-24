#include <iostream>
#include <vector>
using namespace std;
bool canPartition(vector<int>& nums)
{
	//计算nums数组中所有数的总和，如果总和除以2有余数说明不能被分为两个和相等的子区间
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum % 2 != 0)
		return false;
	int bagmax = sum / 2;
	vector<int> dp(bagmax + 1, 0);
	//dp数组下标表示当前背包容量为j，内容表示当前0-i物品中任意取可以得到的最大价值，物品的重量和价值都是nums数组
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = bagmax; j >= nums[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		}
	}
	//如果最大价值能达到sum的一半，说明在nums中能找出两组相等的子区间
	if (dp[bagmax] == bagmax)
		return true;
	else
		return false;
}
void test()
{
	vector<int> nums = { 1,5,11,5 };
	cout << canPartition(nums) << endl;
}
int main()
{
	test();
	return 0;
}