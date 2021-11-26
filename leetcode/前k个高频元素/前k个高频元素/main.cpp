#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
	//法一：将所有数据暴力存入优先级队列，直接取前k个
	vector<int> topK(vector<int>& nums, int k)
	{
		unordered_map<int, int> map;
		priority_queue<pair<int, int>> pq;       //大根堆
		vector<int> ret;
		for (auto e : nums)             //key为nums中的值，value为该值出现的次数
		{
			map[e]++;
		}
		unordered_map<int, int>::iterator it = map.begin();
		while (it != map.end())         //以出现次数为排序标准，存入大根堆中,堆顶是出现次数最多的元素
		{
			pq.push(pair<int, int>(it->second, it->first));
			it++;
		}
		for (int i = 0; i < k; i++)     //将堆顶存入ret，循环k次，即前k个出现次数最多的数
		{
			ret.push_back(pq.top().second);
			pq.pop();
		}
		return ret;
	}
	//法二：控制优先级队列中数据量保持在k，采用小根堆实现，每次数据大于k时，将堆顶（最小）元素弹出
	vector<int> topK1(vector<int>& nums, int k)
	{
		unordered_map<int, int> map;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> ret(k);
		for (auto e : nums)
		{
			map[e]++;
		}
		for (auto e : map)
		{
			pq.push(pair<int, int>(e.second, e.first));
			if (pq.size() > k)
				pq.pop();
		}
		for (int i = pq.size() - 1; i >= 0; i--)
		{
			ret[i] = pq.top().second;
			pq.pop();
		}
		return ret;
	}
};

void test()
{
	Solution s;
	vector<int> nums = { 1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,5,5 };
	vector<int> res;
	res = s.topK(nums, 3);
	for (int e : res)
	{
		cout << e << " ";
	}
	cout << endl;
	res = s.topK1(nums, 3);
	for (int e : res)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}