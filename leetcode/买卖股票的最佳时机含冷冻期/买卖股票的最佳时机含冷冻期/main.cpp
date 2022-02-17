#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	//״̬0����ǰ���ڳ��й�Ʊ״̬
	//״̬1������������Ʊ
	//״̬2������ǰ������Ʊ,�Ҷȹ����䶳��,����������Ʊ״̬
	//״̬3����ǰ�����䶳��
	vector<vector<int>> dp(nums.size(), vector<int>(4, 0));
	dp[0][0] = -nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]) - nums[i]);
		dp[i][1] = dp[i - 1][0] + nums[i];
		dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);
		dp[i][3] = dp[i - 1][1];
	}
	int n = nums.size() - 1;
	return max(dp[n][1], max(dp[n][2], dp[n][3]));
}
void test()
{
	vector<int> nums = { 1,2,3,0,2 };
	cout << maxProfit(nums) << endl;
}
int main()
{
	test();
	return 0;
}