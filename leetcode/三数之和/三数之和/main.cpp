#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ret;
		if (nums.size() < 3)       //如果nums中不够三个数据，直接返回
			return ret;
		sort(nums.begin(), nums.end());  //将nums中的数据从小到大排序
		for (int first = 0; first < nums.size() - 2; first++)
		{
			if (nums[first] > 0)   //如果第一个元素已经大于0，那么不可能有组合等于0，直接返回
				return ret;
			if (first > 0 && nums[first] == nums[first - 1]) //如果第一个元素已经出现过，跳过这个元素
				continue;
			int target = 0 - nums[first];
			int right = nums.size() - 1;
			int lift = first + 1;
			while (lift < right)
			{
				if (lift > first + 1 && nums[lift] == nums[lift - 1])  //如果这个元素在上一轮循环已经出现，直接跳过，防止重复
				{
					lift++;
					continue;
				}
				if (nums[lift] + nums[right] == target)   //如果符合条件，将这三个元素存入ret中，并继续遍历
				{
					ret.push_back({ nums[first],nums[lift],nums[right] });
					lift++;
					right--;
				}
				else if (nums[lift] + nums[right] > target) //如果这两个元素的和比预期值大，右指针左移，将和减小
				{
					right--;
				}
				else     //如果这两个元素的和比预期值小，左指针右移，将和增大
				{
					lift++;
				}
			}

		}
		return ret;
	}
};
void test()
{
	vector<int> v = { -1,0,1,2,-1,-4 };
	Solution s;
	vector<vector<int>> vv;
	vv = s.threeSum(v);
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