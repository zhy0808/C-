#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	/*vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;
		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			for (size_t j = i + 1; i < nums.size(); j++)
			{
				if (nums.at(i) + nums.at(j) == target)
				{
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
	}*/
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> ret;
		unordered_map<int, int> map;
		for (size_t i = 0; i < nums.size(); i++)
		{
			auto it = map.find(target - nums[i]);//当遍历到当前位置时，在map中找有没有符合条件的值
			if (it != map.end())                 //如果有，记录下标
			{
				ret.push_back(it->second);
				ret.push_back(i);
				break;
			}
			else                                 //如果没有，把当前位置的值和下标存入map
			{
				map.insert(pair<int, int>(nums[i], i));
			}
		}
		return ret;
	}
};
void test()
{
	Solution s;
	vector<int> v = { 1,2,3,4,7,8,9 };
	vector<int> ans;
	ans = s.twoSum(v, 7);
	for (auto e : ans)
	{
		cout << e << endl;
	}
}

int main()
{
	test();
	return 0;
}