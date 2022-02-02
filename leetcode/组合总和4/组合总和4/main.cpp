#include <iostream>
#include <vector>
using namespace std;
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= target; ++j)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= j && dp[j] < (INT_MAX - dp[j - nums[i]]))
                dp[j] += dp[j - nums[i]];
        }
    }
    return dp[target];
}
void test()
{
    vector<int> nums = { 1,2,3 };
    cout << combinationSum4(nums, 4) << endl;
}
int main()
{
	test();
	return 0;
}