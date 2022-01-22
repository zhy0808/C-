#include <iostream>
#include <vector>
using namespace std;

int bag(vector<int>& weight, vector<int>& val, int bagmax)
{
	//dp数组下标i代表第i个物品，j代表背包容量，dp[i][j]代表背包容量为j时，从物品0-i中任意取物品可以得到的最大价值
	vector<vector<int>> dp(weight.size(), vector<int>(bagmax + 1, 0));
	//先初始化往背包容量从0-max里装第一个物品的得到的总价值，因为后面的情况都要基于装第一个物品的总价值
	for (int j = 0; j < bagmax; ++j)
	{
		//如果当前背包容量小于第一个物品的重量，代表装不进去，继续遍历增加背包的容量
		//如果能装进去，就把dp数组对应位置的值置为第一个物品的价值
		if (j >= weight[0])
			dp[0][j] = val[0];
	}
	//当背包容量为j时，计算从i个物品取任意个得到的最大价值
	for (int i = 1; i < weight.size(); ++i)
	{
		for (int j = 0; j <= bagmax; ++j)
		{
			//如果当前背包容量小于第i个物品的重量，说明装不下第i个，则最大价值为在0-（i-1）里面选任意个的最大价值
			if (j < weight[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			//如果当前背包容量能装下第i个物品，则比较在0-i里面装第i个物品后的最大价值和不装第i个物品的最大价值，取更大值
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + val[i]);
			}
		}
	}
	return dp[weight.size() - 1][bagmax];
}

void test()
{
	vector<int> weight = { 1, 3, 4 };
	vector<int> val = { 15, 20, 30 };
	cout << bag(weight, val, 4) << endl;
}
int main()
{

	test();
	return 0;
}