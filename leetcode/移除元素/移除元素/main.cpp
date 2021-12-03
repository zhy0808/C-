#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void removeElement(vector<int>& nums, int val)
	{
		int slow = 0, fast = 0;
		while (fast < nums.size())          //fastָ�������Чֵ������Чֵ����Ҫ�Ƴ���ֵ
		{
			if (nums[fast] != val)
				nums[slow++] = nums[fast++];
			else
				fast++;
		}
		nums.resize(slow);
	}
};
void test()
{
	Solution s;
	vector<int> v = { 3,2,2,3 };
	s.removeElement(v, 3);
	for (auto e : v)
	{
		cout << e << endl;
	}
}
int main()
{
	test();

	return 0;
}