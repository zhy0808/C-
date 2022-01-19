#include <iostream>
#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& nums)
{
	int m = nums.size();
	int n = nums.size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	for (int i = 0; i < m; ++i)
	{
		if (nums[i][0] == 1)//������λ�����ϰ���Ͳ��ڳ�ʼ�������λ�ã���Ϊ��·����
			break;
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; ++j)
	{
		if (nums[0][j] == 1)
			break;
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (nums[i][j] == 1)   //�����ǰλ�����ϰ���Ͳ��ټ���dp�����е�ǰλ�õ�ֵ��Ϊ0���ɣ���Ϊû�����ߵ��ϰ����·��
				continue;
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	return dp[m - 1][n - 1];
}
void test()
{
	vector<vector<int>> nums = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
	cout << uniquePathsWithObstacles(nums) << endl;
}
int main()
{
	test();
	return 0;
}