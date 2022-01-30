#include <iostream>
#include <vector>
using namespace std;

int change(vector<int>& coins, int amount)
{
	//dp�����±����ճɵ��ܽ����ݴ���ճɸý���ж����ַ���
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < coins.size(); ++i)
	{
		for (int j = coins[i]; j <= amount; ++j)
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	return dp[amount];
}
void test()
{
	vector<int> coins = { 1,2,5 };
	cout << change(coins, 5) << endl;
}
int main()
{
	test();
	return 0;
}