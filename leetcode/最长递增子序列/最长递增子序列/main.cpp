#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
	//dp��������ݴ�����ǰλ�������������еĳ���
	vector<int> dp(nums.size(), 1);
	int ret = 1;
	//����ÿһ��λ�������������еĳ���
	for (int i = 1; i < nums.size(); ++i)
	{
		//��ǰλ�������������еĳ�����ǰ��ÿ��λ�������������е����ֵ
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] > nums[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		//�������ĵ��������г���
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