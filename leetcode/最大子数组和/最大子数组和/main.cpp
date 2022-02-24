#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	//dp[i]��ʾnums������nums[i]��β�����������������
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	int ret = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{

		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		//dp[i]�����ֵ���ǽ��
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