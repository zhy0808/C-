#include <iostream>
#include <vector>
using namespace std; 
//��ʯͷ��Ϊ�����֣�һ���ֳ�-1��һ���ֳ�1��-1���ֵ��ܺ�Ϊbagmax����1���ֵ��ܺ;�Ϊsum-bagmax
// ������ʯͷ������������ս��Ϊ(sum-bagmax)-bagmax=sum - 2*bagmax
// ��Ҫ���ս����С����bagmaxҪȡ���ֵ������������sum/2
// ���Ը���ת��Ϊ����������Ϊsum/2�������װ��ʯͷ���������ֵ
//������ʯͷ������ӣ���ʯͷ�����ܺ�/2Ϊ�����������ֵ������ñ�����������װ����ʯͷ
//�õ���ʯͷ���������ܵ���������������������ȥ�������Ե������������õ��ľ������ʣ�µ�����
int lastStoneWeightII(vector<int>& stones)
{
	int sum = 0;
	for (int i = 0; i < stones.size(); ++i)
	{
		sum += stones[i];
	}
	int bagmax = sum / 2;
	vector<int> dp(bagmax + 1, 0);
	for (int i = 0; i < stones.size(); ++i)
	{
		for (int j = bagmax; j >= stones[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
		}
	}
	return sum - 2 * dp[bagmax];
}
void test()
{
	vector<int> stones = { 2,7,4,1,8,1 };
	cout << lastStoneWeightII(stones) << endl;
}
int main()
{

	test();
	return 0;
}