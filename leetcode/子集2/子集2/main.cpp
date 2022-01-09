//�����а����ظ�Ԫ��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void find(vector<int>& nums, vector<vector<int>>& ret, vector<int> path, int begin)
{
	ret.push_back(path);
	if (begin == nums.size())
		return;
	for (int i = begin; i < nums.size(); i++)
	{
		if (i > begin && nums[i] == nums[i - 1])   //�����ǰ���Ѿ�ʹ�ù���Ԫ�أ�ֱ������
			continue;
		path.push_back(nums[i]);
		find(nums, ret, path, i + 1);
		path.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> ret;
	vector<int> path;
	sort(nums.begin(), nums.end());          //����Ϊ����ȥ����
	find(nums, ret, path, 0);
	return ret;
}

void test()
{
	vector<int> nums = { 4,4,4,1,4 };
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