#include <iostream>
#include <vector>
using namespace std;
int maxProfit(int k, vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	vector<vector<int>> dp(nums.size(), vector<int>(2 * k + 1, 0));
	//��0�첻�ܵڼ�����������ǰ���������Ϊ����һ��Ĺɼ�
	for (int j = 1; j < 2 * k + 1; j += 2)
	{
		dp[0][j] = -nums[0];
	}
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = 0; j < 2 * k - 1; j += 2)
		{
			//��i��ڣ�j+1��%2�γ��й�Ʊ���������
			dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - nums[i]);
			//��i��ڣ�j+2��/2�β����й�Ʊ���������
			dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + nums[i]);
		}
	}
	return dp[nums.size() - 1][2 * k];
}
void test()
{
	vector<int> nums = { 3,2,6,5,0,3 };
	cout << maxProfit(2, nums) << endl;
}
int main()
{
	test();
	return 0;
}