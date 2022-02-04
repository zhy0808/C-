#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
	//dp数组下标代表要兑换的金额，内容代表要兑换下标金额的钱最少需要几个硬币
	//将数组初始化为整数的最大值，便于后续比较
	//兑换0元最少需要0个硬币
	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	//完全背包，背包容量为amount，求装满背包所需要的最少物品数
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