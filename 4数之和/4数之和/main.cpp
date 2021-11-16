#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> ret;
		if (nums.size() < 4)           //nums中的数小于4个，直接返回
			return ret;
		sort(nums.begin(), nums.end());//从小到大排序
		for (int a = 0; a < nums.size() - 3; a++)
		{
			if (a > 0 && nums[a] == nums[a - 1])  //如果当前元素与上一轮的值相同，跳过该元素，防止重复
				continue;
			for (int b = a + 1; b < nums.size() - 2; b++)
			{
				if (b > a + 1 && nums[b] == nums[b - 1])  //同理，防止出现重复
					continue;
				int right = nums.size() - 1;
				int lift = b + 1;
				int difference = target - nums[a] - nums[b];
				while (lift < right)
				{
					if (lift > b + 1 && nums[lift] == nums[lift - 1]) //同理，防止出现重复
					{
						lift++;
						continue;
					}
					if (nums[lift] + nums[right] > difference)    
						right--;
					else if (nums[lift] + nums[right] < difference)
						lift++;
					else
					{
						ret.push_back({ nums[a],nums[b],nums[lift],nums[right] });
						lift++;
						right--;
					}
				}
			}
		}
		return ret;

	}
};
void test()
{
	Solution s;
	vector<int> v = { 1,0,-1,0,-2,2 };
	vector<vector<int>> vv;
	vv = s.fourSum(v, 0);
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	test();
	return 0;
}