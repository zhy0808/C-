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
			auto it = map.find(target - nums[i]);//����������ǰλ��ʱ����map������û�з���������ֵ
			if (it != map.end())                 //����У���¼�±�
			{
				ret.push_back(it->second);
				ret.push_back(i);
				break;
			}
			else                                 //���û�У��ѵ�ǰλ�õ�ֵ���±����map
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