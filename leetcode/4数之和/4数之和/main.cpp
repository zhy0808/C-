#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> ret;
		if (nums.size() < 4)           //nums�е���С��4����ֱ�ӷ���
			return ret;
		sort(nums.begin(), nums.end());//��С��������
		for (int a = 0; a < nums.size() - 3; a++)
		{
			if (a > 0 && nums[a] == nums[a - 1])  //�����ǰԪ������һ�ֵ�ֵ��ͬ��������Ԫ�أ���ֹ�ظ�
				continue;
			for (int b = a + 1; b < nums.size() - 2; b++)
			{
				if (b > a + 1 && nums[b] == nums[b - 1])  //ͬ����ֹ�����ظ�
					continue;
				int right = nums.size() - 1;
				int lift = b + 1;
				int difference = target - nums[a] - nums[b];
				while (lift < right)
				{
					if (lift > b + 1 && nums[lift] == nums[lift - 1]) //ͬ����ֹ�����ظ�
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