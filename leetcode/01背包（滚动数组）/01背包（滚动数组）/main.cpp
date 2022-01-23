#include <iostream>
#include <vector>
using namespace std;


int bag(vector<int>& weight, vector<int>& val, int bagmax)
{
	//dp数组下标表示背包容量，内容表示当前被包容量能装的最大价值
	vector<int> dp(bagmax + 1, 0);
	//遍历物品
	for (int i = 0; i < weight.size(); ++i)
	{
		//从大到小（防止重复计算同一物品）遍历背包容量，计算当前容量的背包可以装进物品的最大价值
		for (int j = bagmax; j >= weight[i]; --j)
		{
			//当前容量背包能装物品的最大价值要么是不装第i件物品，即上一层0-（i-1）物品中的最大价值，
			//要么是装进第i件物品，即0-i物品中选出的最大价值
			dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
		}
	}
	return dp[bagmax];
}

void test()
{
	vector<int> weight = { 1,3,4 };
	vector<int> val = { 15,20,30 };
	cout << bag(weight, val, 4) << endl;
}
int main()
{


	test();
	return 0;
}