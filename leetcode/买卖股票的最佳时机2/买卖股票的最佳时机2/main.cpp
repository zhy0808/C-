#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& nums)
{
	int ret = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		ret += max(0, nums[i] - nums[i - 1]);
	}
	return ret;
}
void test()
{
	vector<int> nums = { 7,1,5,3,6,4 };
	cout << maxProfit(nums) << endl;
}
int main()
{
	test();
	return 0;
}