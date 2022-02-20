#include <iostream>
#include <vector>
using namespace std;
int findLengthOfLCIS(vector<int>& nums)
{
	//dp�������ݴ���ǰλ�õ�����������������г���
	vector<int> dp(nums.size(), 1);
	int ret = 1;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		//�����һ�����ȵ�ǰ����dp[i + 1] = dp[i] + 1
		if (nums[i] < nums[i + 1])
			dp[i + 1] += dp[i];
		if (dp[i + 1] > ret)
			ret = dp[i + 1];
	}
	return ret;
}
void test()
{
	vector<int> nums = { 1,3,5,4,7 };
	cout << findLengthOfLCIS(nums) << endl;
}
int main()
{
	test();
	return 0;
}