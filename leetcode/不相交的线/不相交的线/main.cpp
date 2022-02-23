#include <iostream>
#include <vector>
using namespace std;
int func(vector<int>& nums1, vector<int>& nums2)
{
	//dp[i][j]代表nums1[0--i-1]和nums2[0—j-1]的公共子序列最长的长度
	vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
	for (int i = 1; i <= nums1.size(); ++i)
	{
		for (int j = 1; j <= nums2.size(); ++j)
		{
			if (nums1[i - 1] == nums2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max( dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[nums1.size()][nums2.size()];
}
void test()
{
	vector<int> nums1 = { 1,2,3 };
	vector<int> nums2 = { 1,3,2 };
	cout << func(nums1, nums2) << endl;
}
int main()
{
	test();
	return 0;
}