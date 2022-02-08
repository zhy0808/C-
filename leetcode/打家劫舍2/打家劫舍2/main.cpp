#include <iostream>
#include <vector>
using namespace std;
//���ҽ���1��ȣ����˲��ܳɻ�������ֻ��Ҫ�����ѡ��һ�Ҳ�ѡ���һ�Һ�ѡ���һ�Ҳ�ѡ��һ�ҵĽϴ�ֵ
int rob1(vector<int>& nums, int begin, int end)
{
	if (begin == end)
		return nums[begin];
	vector<int> dp(nums.size() - 1, 0);
	dp[0] = nums[begin];
	dp[1] = max(nums[begin], nums[begin + 1]);
	for (int i = 2; i < nums.size() - 1; ++i)
	{
		dp[i] = max(dp[i - 2] + nums[begin + i], dp[i - 1]);
	}
	return dp[nums.size() - 2];
}
int rob2(vector<int>& nums)
{
	if (nums.size() == 1)
		return nums[0];
	return max(rob1(nums, 0, nums.size() - 2), rob1(nums, 1, nums.size() - 1));
}
void test()
{
	vector<int> nums = { 1,2,3,1 };
	cout << rob2(nums) << endl;
}
int main()
{
	test();
	return 0;
}