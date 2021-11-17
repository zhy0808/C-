#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
	{
		unordered_map<int, int> map; //������¼����nums1�е����ݼ�nums2�е����ݵĺͣ�key����ÿ���ͳ��ֵĴ�����value��
		int count = 0;
		for (auto a : nums1)
		{
			for (auto b : nums2)
			{
				map[a + b]++;      //keyΪa+b,valueΪa+b���ֵĴ���
			}
		}
		for (auto c : nums3)
		{
			for (auto d : nums4)
			{
				if (map.find(0 - (c + d)) != map.end())  //���map�д���key=0-(c+d),��a+b=0-(c+d)=>a+b+c+d=0,��¼��ǰa+b���ֵĴ�����Ҳ���Ƕ�Ӧ��value
				{
					count += map[0 - (c + d)];
				}
			}
		}
		return count;

	}
};
void test()
{
	vector<int> v1 = { 1,2 };
	vector<int> v2 = { -1,-2 };
	vector<int> v3 = { -1,2 };
	vector<int> v4 = { 0,2 };
	Solution s;
	cout << s.fourSumCount(v1, v2, v3, v4) << endl;

}
int main()
{
	test();
	return 0;
}