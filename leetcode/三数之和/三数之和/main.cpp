#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> ret;
		if (nums.size() < 3)       //���nums�в����������ݣ�ֱ�ӷ���
			return ret;
		sort(nums.begin(), nums.end());  //��nums�е����ݴ�С��������
		for (int first = 0; first < nums.size() - 2; first++)
		{
			if (nums[first] > 0)   //�����һ��Ԫ���Ѿ�����0����ô����������ϵ���0��ֱ�ӷ���
				return ret;
			if (first > 0 && nums[first] == nums[first - 1]) //�����һ��Ԫ���Ѿ����ֹ����������Ԫ��
				continue;
			int target = 0 - nums[first];
			int right = nums.size() - 1;
			int lift = first + 1;
			while (lift < right)
			{
				if (lift > first + 1 && nums[lift] == nums[lift - 1])  //������Ԫ������һ��ѭ���Ѿ����֣�ֱ����������ֹ�ظ�
				{
					lift++;
					continue;
				}
				if (nums[lift] + nums[right] == target)   //���������������������Ԫ�ش���ret�У�����������
				{
					ret.push_back({ nums[first],nums[lift],nums[right] });
					lift++;
					right--;
				}
				else if (nums[lift] + nums[right] > target) //���������Ԫ�صĺͱ�Ԥ��ֵ����ָ�����ƣ����ͼ�С
				{
					right--;
				}
				else     //���������Ԫ�صĺͱ�Ԥ��ֵС����ָ�����ƣ���������
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