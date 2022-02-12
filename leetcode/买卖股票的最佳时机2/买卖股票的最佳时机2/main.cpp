#include <iostream>
#include <vector>
using namespace std;
//̰��
int maxProfit(vector<int>& nums)
{
	int ret = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		ret += max(0, nums[i] - nums[i - 1]);
	}
	return ret;
}
//��̬�滮
int maxProfit2(vector<int>& nums)
{
	vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = -nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		//��i�첻���й�Ʊ���������ȡǰһ�첻���й�Ʊ����������ǰһ����й�Ʊ����������Ʊ�ĸ���ֵ
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - nums[i]);
	}
	return dp[nums.size() - 1][0];
}
void test()
{
	vector<int> nums = { 7,1,5,3,6,4 };
	cout << maxProfit(nums) << endl;
	cout << maxProfit2(nums) << endl;
}
int main()
{
	test();
	return 0;
}