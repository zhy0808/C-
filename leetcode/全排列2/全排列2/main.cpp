#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void find(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, int* used)
{
	if (path.size() == nums.size())
	{
		ret.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		//��������е�ǰλ�õ������Ѿ���ʹ�ù������ߵ�ǰλ����ǰһ��λ�õ�ֵ��ͬ��ǰһ��λ����ͬһ��forѭ����ʹ�ù�
		//��ͬһ��forѭ��������iλ��ʱ��i-1λ�ÿ϶���ʹ�ù�����־����used[i-1]=0������������ǰλ��
		if (used[i] == 1 || (i > 0 && (nums[i] == nums[i - 1]) && (used[i - 1] == 0)))
			continue;
		else
		{
			path.push_back(nums[i]);
			used[i] = 1;
			find(nums, ret, path, used);
			used[i] = 0;
			path.pop_back();
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> ret;
	vector<int> path;
	int used[10] = { 0 };
	sort(nums.begin(), nums.end());   //����ȥ��
	find(nums, ret, path, used);
	return ret;
}
void test()
{
	vector<int> nums = { 1,1,2 };
	vector<vector<int>> ret;
	ret = permuteUnique(nums);
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