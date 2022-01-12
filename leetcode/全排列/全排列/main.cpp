//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
//1 <= nums.length <= 6
//-10 <= nums[i] <= 10
//nums �е��������� ������ͬ



#include <iostream>
#include <vector>
using namespace std;

void find(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, vector<int>& flag)
{
	if (path.size() == nums.size())
	{
		ret.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (flag[nums[i] + 10] == 1)
			continue;
		else
		{
			path.push_back(nums[i]);
			flag[nums[i] + 10] = 1;
			find(nums, ret, path, flag);
			flag[path.back() + 10] = 0;
			path.pop_back();
		}
	}
}
vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> ret;
	vector<int> path;
	vector<int> flag;
	flag.resize(21, 0);            //��������е����Ƿ��Ѿ���ʹ��
	find(nums, ret, path, flag);
	return ret;
}
void test()
{
	vector<vector<int>> ret;
	vector<int> nums = { 1,2,3 };
	ret = permute(nums);
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