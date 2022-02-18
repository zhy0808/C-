#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& nums, int fee)
{
	if (nums.size() == 0)
		return 0;
	vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
	//ÿ�������Ʊʱ�۳�������
	dp[0][1] = -nums[0] - fee;
	for (int i = 1; i < nums.size(); ++i)
	{
		//δ���й�Ʊ�������δ���л�������н�������
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
		//���й�Ʊ������ͳ��л�����δ���н�������
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