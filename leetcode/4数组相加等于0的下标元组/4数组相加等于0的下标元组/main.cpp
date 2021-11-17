#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
	{
		unordered_map<int, int> map; //用来记录所有nums1中的数据加nums2中的数据的和（key）和每个和出现的次数（value）
		int count = 0;
		for (auto a : nums1)
		{
			for (auto b : nums2)
			{
				map[a + b]++;      //key为a+b,value为a+b出现的次数
			}
		}
		for (auto c : nums3)
		{
			for (auto d : nums4)
			{
				if (map.find(0 - (c + d)) != map.end())  //如果map中存在key=0-(c+d),即a+b=0-(c+d)=>a+b+c+d=0,记录当前a+b出现的次数，也就是对应的value
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