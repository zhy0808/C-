#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
	//dp数组的内容代表到当前位置最大递增子序列的长度
	vector<int> dp(nums.size(), 1);
	int ret = 1;
	//计算每一个位置最大递增子序列的长度
	for (int i = 1; i < nums.size(); ++i)
	{
		//当前位置最大递增子序列的长度是前面每个位置最大递增子序列的最大值
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] > nums[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		//保存最大的递增子序列长度
		if (dp[i] > ret)
			ret = dp[i];
	}
	return ret;
}
void test()
{
	vector<int> nums = { 10,9,2,5,3,7,101,18 };
	cout << lengthOfLIS(nums) << endl;
}
int main()
{
	test();
	return 0;
}