#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	//Ë«Ö¸Õë
	void removeDuplicates(vector<int>& nums)
	{
		if (nums.size() < 2)
			return;
		int slow = 0;
		int fast = 1;
		while (fast < nums.size())
		{
			if (nums[fast] != nums[slow])
				nums[++slow] = nums[fast++];
			else
				fast++;
		}
		nums.resize(slow + 1);

	}
};
void test()
{
	Solution s;
	vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
	s.removeDuplicates(v);
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