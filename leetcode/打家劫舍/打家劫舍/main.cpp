#include <iostream>
#include <vector>
using namespace std;
//dp�������ݴ�����ǰi����������͵����Ǯ
int rob(vector<int>& nums)
{
	if (nums.size() == 1)
		return nums[0];
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); ++i)
	{
		//ÿ�ο���ѡ��͵��i�һ��߲�͵��i��
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