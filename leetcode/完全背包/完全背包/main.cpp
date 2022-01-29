#include <iostream>
#include <vector>
using namespace std;
//把01背包中倒着遍历背包改为顺序遍历即可，倒着遍历就是为了防止物品重复，完全背包中物品可以重复
int CompletePack(vector<int>& weight, vector<int>& val, int bagmax)
{
	vector<int> dp(bagmax + 1, 0);
	for (int i = 0; i < weight.size(); ++i)
	{
		for (int j = weight[i]; j <= bagmax; ++j)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
		}
	}
	return dp[bagmax];
}
void test()
{
	vector<int> weight = { 1,3,4 };
	vector<int> val = { 15,20,30 };
	cout << CompletePack(weight, val, 4) << endl;
}
int main()
{
	test();
	return 0;
}