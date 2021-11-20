#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		deque<int> dq;           //双端队列
		vector<int> ret;
		for (int i = 0; i < k; i++)  //将第一个窗口中的数据放入双端队列，并保证这些数从大到小排列
		{
			while (!dq.empty() && nums[i] > dq.back()) //如果新进队列的数比他的前一个大，让他的前一个数出队
			{
				dq.pop_back();
			}
			dq.push_back(nums[i]);  //前面都是比新进队的数大了，让这个数入队
		}
		ret.push_back(dq.front());  //第一个窗口的最大值就是当前队头
		for (int i = k; i < nums.size(); i++)  //窗口向后滑动
		{
			if (dq.front() == nums[i - k])     //把不属于这个窗口的数据移出队列
				dq.pop_front();
			while (!dq.empty() && nums[i] > dq.back())  //如果新进队的数比队中它之前的数据大，让他的前一个数出队
			{
				dq.pop_back();
			}
			dq.push_back(nums[i]);       //前面的数都比该数大了，让这个数入队
			ret.push_back(dq.front());   //当前窗口最大值就是队头
		}
		return ret;
	}
};
void test()
{
	Solution s;
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> res;
	res = s.maxSlidingWindow(nums, 3);
	for (auto e : res)
	{
		cout << e << endl;
	}
}
int main()
{
	test();
	return 0;
}