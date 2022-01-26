#include <iostream>
#include <vector>
using namespace std;
//����������Ϊ�����֣���߼��ұߵõ�tar������߼��ұߵõ�sum
//left-right=tar            left+right=sum   (tar�ľ���ֵ�ض�ҪС��sum�����򲻹�left��right���ӷ����Ǽ������ò���tar)
//����ʽ�õ���2*left = tar+sum               (tar+sum�ض�Ϊż��)
//left = (tar+sum)/2    ����������Ϊ(tar+sum)/2,���nums������ȡ�������ж����ַ������Է�������
int findTargetSumWays(vector<int>& nums, int tar)
{
	int sum = 0;
	for (auto e : nums)
	{
		sum += e;
	}
	if (sum < abs(tar) || (sum + tar) % 2 != 0)
		return 0;
	int bagmax = (sum + tar) / 2;
	vector<int> dp(bagmax + 1, 0);
	dp[0] = 1;       //�����ռ�Ϊ0ʱ����һ�ַ���װ�������ǲ�װ
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = bagmax; j >= nums[i]; --j)
		{
			dp[j] += dp[j - nums[i]];//����i����Ʒ����������Ϊjʱ��������װ���ķ������������
		}
	}
	return dp[bagmax];
}
void test()
{
	vector<int> nums = { 1,1,1,1,1 };
	cout << findTargetSumWays(nums, 3) << endl;
}
int main()
{
	test();
	return 0;
}