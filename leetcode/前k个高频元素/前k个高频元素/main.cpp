#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
	//��һ�����������ݱ����������ȼ����У�ֱ��ȡǰk��
	vector<int> topK(vector<int>& nums, int k)
	{
		unordered_map<int, int> map;
		priority_queue<pair<int, int>> pq;       //�����
		vector<int> ret;
		for (auto e : nums)             //keyΪnums�е�ֵ��valueΪ��ֵ���ֵĴ���
		{
			map[e]++;
		}
		unordered_map<int, int>::iterator it = map.begin();
		while (it != map.end())         //�Գ��ִ���Ϊ�����׼������������,�Ѷ��ǳ��ִ�������Ԫ��
		{
			pq.push(pair<int, int>(it->second, it->first));
			it++;
		}
		for (int i = 0; i < k; i++)     //���Ѷ�����ret��ѭ��k�Σ���ǰk�����ִ���������
		{
			ret.push_back(pq.top().second);
			pq.pop();
		}
		return ret;
	}
	//�������������ȼ�������������������k������С����ʵ�֣�ÿ�����ݴ���kʱ�����Ѷ�����С��Ԫ�ص���
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