#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& nums)
{
	int leftmin = INT_MAX; //��¼ǰ���������С�۸�
	int ret = 0;           //��¼�����ǰ���������Եõ����������
	for (int i = 0; i < nums.size(); ++i)
	{
		leftmin = min(leftmin, nums[i]);
		//��ǰ����������Ϊ��ǰ������������͵�ǰ��Ĺɼۼ�ȥ��С�ɼ۵Ľϴ�ֵ
		ret = max(ret, nums[i] - leftmin);
	}
	return ret;
}
int maxProfit2(vector<int>& nums)
{
	//�±�����i�죬���ݴ���ǰi����������
	vector<int> dp(nums.size() + 1, 0);
	int leftmin = INT_MAX;
	for (int i = 1; i <= nums.size(); ++i)
	{
		leftmin = min(nums[i - 1], leftmin);
		dp[i] = max(dp[i - 1], nums[i - 1] - leftmin);
	}
	return dp[nums.size()];
}
void test()
{
	vector<int> nums = { 2,5,1,3 };
	cout << maxProfit(nums) << endl;
	cout << maxProfit2(nums) << endl;
}

int main()
{
	test();
	return 0;
}