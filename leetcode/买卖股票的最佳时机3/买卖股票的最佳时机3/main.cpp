#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    //第0天首次持有股票的最大利润
    dp[0][1] = -prices[0];
    //第0天第二次持有股票的最大利润
    dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[prices.size() - 1][4];
}
void test()
{
	vector<int> prices = { 3,3,5,0,0,3,1,4 };
    cout << maxProfit(prices) << endl;
}
int main()
{
	test();
	return 0;
}