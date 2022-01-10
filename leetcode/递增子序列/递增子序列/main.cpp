#include <iostream>
#include <vector>
using namespace std;

void find(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, int begin)
{
	if (path.size() > 1)
		ret.push_back(path);
	if (begin == nums.size())
		return;
	int map[201] = { 0 };
	for (int i = begin; i < nums.size(); i++)
	{
		if ((path.size() != 0 && nums[i] < path.back()) || map[nums[i] + 100] == 1)
			continue;
		path.push_back(nums[i]);
		map[nums[i] + 100] = 1;
		find(nums, ret, path, i + 1);
		path.pop_back();
	}
}

vector<vector<int>> findSubsequences(vector<int>& nums)
{
	vector<vector<int>> ret;
	vector<int> path;
	find(nums, ret, path, 0);
	return ret;
}
void test()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,1,1,1,1,1 };
	vector<vector<int>> ret;
	ret = findSubsequences(nums);
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