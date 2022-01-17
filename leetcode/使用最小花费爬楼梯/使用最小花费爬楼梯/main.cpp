#include <iostream>
#include <vector>
using namespace std;
//dp数组下标代表到达某一层，内容代表想要到达下标层需要的最少总钱数
int minCostClimbingStairs(vector<int>& cost)
{
	if (cost.size() < 3)
		return min(cost[0], cost[1]);
	vector<int> dp(cost.size());
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < cost.size(); ++i)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}
	return min(dp[dp.size() - 1], dp[dp.size() - 2]);
}
void test()
{
	vector<int> cost = { 1,100,1,1,1,100,1,1,100, 1 };
	cout << minCostClimbingStairs(cost) << endl;
}
int main()
{

	test();
	return 0;
}