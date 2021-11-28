#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void moveZeros(vector<int>& nums)
	{
		int slow = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[slow] == 0 && nums[i] != 0)
				swap(nums[slow++], nums[i]);
			else if (nums[slow] != 0)
				slow++;
		}
	}
};
void test()
{
	Solution s;
	vector<int> v = { 0,1,0,3,12 };
	s.moveZeros(v);
	for (auto e : v)
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