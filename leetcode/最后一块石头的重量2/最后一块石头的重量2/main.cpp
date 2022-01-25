#include <iostream>
#include <vector>
using namespace std; 
//将石头分为两部分，一部分乘-1，一部分乘1，-1部分的总和为bagmax，则1部分的总和就为sum-bagmax
// 则所有石头经过粉碎的最终结果为(sum-bagmax)-bagmax=sum - 2*bagmax
// 想要最终结果最小，则bagmax要取最大值，即尽量靠近sum/2
// 所以该题转化为，背包容量为sum/2，求可以装进石头重量的最大值
//将若干石头重量相加，以石头重量总和/2为背包重量最大值，计算该背包中最多可以装多少石头
//得到的石头重量就是能抵消的重量，用总重量减去二倍可以抵消的重量，得到的就是最后剩下的重量
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