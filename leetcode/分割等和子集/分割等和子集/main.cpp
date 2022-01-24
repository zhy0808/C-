#include <iostream>
#include <vector>
using namespace std;
bool canPartition(vector<int>& nums)
{
	//����nums���������������ܺͣ�����ܺͳ���2������˵�����ܱ���Ϊ��������ȵ�������
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum % 2 != 0)
		return false;
	int bagmax = sum / 2;
	vector<int> dp(bagmax + 1, 0);
	//dp�����±��ʾ��ǰ��������Ϊj�����ݱ�ʾ��ǰ0-i��Ʒ������ȡ���Եõ�������ֵ����Ʒ�������ͼ�ֵ����nums����
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = bagmax; j >= nums[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		}
	}
	//�������ֵ�ܴﵽsum��һ�룬˵����nums�����ҳ�������ȵ�������
	if (dp[bagmax] == bagmax)
		return true;
	else
		return false;
}
void test()
{
	vector<int> nums = { 1,5,11,5 };
	cout << canPartition(nums) << endl;
}
int main()
{
	test();
	return 0;
}