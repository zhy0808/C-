#include <iostream>
#include <vector>
using namespace std;

void find(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, int begin)
{
	ret.push_back(path);
	if (begin == nums.size())
		return;
	for (int i = begin; i < nums.size(); i++)
	{
		path.push_back(nums[i]);
		find(nums, ret, path, i + 1);
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> ret;
	vector<int> path;
	find(nums, ret, path, 0);
	return ret;
}
void test()
{
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> ret;
	ret = subsets(nums);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{

	test();
	return 0;
}