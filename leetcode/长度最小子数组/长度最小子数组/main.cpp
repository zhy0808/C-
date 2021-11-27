#include <iostream>
#include <windows.h>
#include <vector>
#include <limits.h>
using namespace std;
int minSubArrayLen1(int target, vector<int>& nums) 
{
	size_t lift = 0, right = 0;
	vector<int> v;
	while (lift<nums.size() && right<nums.size())
	{
		int sum = 0;
		for (size_t i = lift; i <= right; i++)
		{
			sum += nums[i];
		}
		if (sum<target)
		{
			right++;
		}
		else
		{
			v.push_back(right - lift + 1);
			lift++;
		}
	}
	if (v.size() == 0)
		return 0;
	int min = v[0];
	for (size_t i = 1; i<v.size(); i++)
	{
		if (v[i]<min)
			min = v[i];
	}
	return min;
}
int minSubArrayLen2(int target, vector<int>& nums) 
{
	size_t lift = 0, right = 0;
	int sum = 0;
	vector<int> v;
	int ret = INT_MAX;
	for (; right < nums.size();right++)
	{
		sum += nums[right];
		while (sum >= target)
		{
			int len = right - lift + 1;
			ret = ret<len ? ret : len;
			sum -= nums[lift++];
		}
	}
	return ret = ret == INT_MAX ? 0 : ret;
}
int main()
{
	vector<int> nums({ 1, 2, 3, 4, 5 });
	int a = 15;
	cout << minSubArrayLen2(a, nums) << endl;
	system("pause");
	return 0;
}