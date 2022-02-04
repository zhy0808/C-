#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
	//dp�����±����Ҫ�һ��Ľ����ݴ���Ҫ�һ��±����Ǯ������Ҫ����Ӳ��
	//�������ʼ��Ϊ���������ֵ�����ں����Ƚ�
	//�һ�0Ԫ������Ҫ0��Ӳ��
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	//��ȫ��������������Ϊamount����װ����������Ҫ��������Ʒ��
	for (int i = 0; i < coins.size(); ++i)
	{
		for (int j = coins[i]; j <= amount; ++j)
		{
			if (dp[j - coins[i]] != INT_MAX)
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	if (dp[amount] == INT_MAX)
		return -1;
	return dp[amount];
}

void test()
{
	vector<int> coins = { 1,2,5 };
	cout << coinChange(coins, 11) << endl;
}
int main()
{
	test();
	return 0;
}