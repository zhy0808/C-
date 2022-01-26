#include <iostream>
#include <vector>
using namespace std;
//把所有数分为两部分，左边减右边得到tar，且左边加右边得到sum
//left-right=tar            left+right=sum   (tar的绝对值必定要小于sum，否则不管left和right做加法还是减法都得不到tar)
//由上式得到：2*left = tar+sum               (tar+sum必定为偶数)
//left = (tar+sum)/2    即背包总量为(tar+sum)/2,求从nums数组中取任意数有多少种方法可以放满背包
int findTargetSumWays(vector<int>& nums, int tar)
{
	int sum = 0;
	for (auto e : nums)
	{
		sum += e;
	}
	if (sum < abs(tar) || (sum + tar) % 2 != 0)
		return 0;
	int bagmax = (sum + tar) / 2;
	vector<int> dp(bagmax + 1, 0);
	dp[0] = 1;       //背包空间为0时，有一种方法装满，就是不装
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = bagmax; j >= nums[i]; --j)
		{
			dp[j] += dp[j - nums[i]];//将有i件物品，背包容量为j时，将背包装满的方法数量计算出
		}
	}
	return dp[bagmax];
}
void test()
{
	vector<int> nums = { 1,1,1,1,1 };
	cout << findTargetSumWays(nums, 3) << endl;
}
int main()
{
	test();
	return 0;
}