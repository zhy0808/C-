#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;


vector<int> sortedSquares1(vector<int>& nums) 
{
	vector<int> ret;
	int lift, right;
	for (size_t i = 0; i<nums.size(); i++)
	{
		if (nums[0] >= 0)
		{
			lift = -1;
			right = 0;
			break;
		}
		if (nums[nums.size() - 1]<0)
		{
			lift = nums.size() - 1;
			right = nums.size();
			break;
		}
		if (nums[i]<0 && nums[i + 1] >= 0)
		{
			lift = i;
			right = i + 1;
			break;
		}
	}
	for (int i = 0; i<nums.size(); i++)
	{
		nums[i] *= nums[i];
	}


	while (lift >= 0 || right<nums.size())
	{
		if (lift<0)
		{
			ret.push_back(nums[right]);
			right++;
		}
		else if (right >= nums.size())
		{
			ret.push_back(nums[lift]);
			lift--;
		}
		else if (nums[lift]>nums[right])
		{
			ret.push_back(nums[right]);
			right++;
		}
		else if (nums[lift] <= nums[right])
		{
			ret.push_back(nums[lift]);
			lift--;
		}
	}
	return ret;
}
vector<int> sortedSquares2(vector<int>& nums) 
{
	vector<int> ret;
	ret.resize(nums.size(), 0);
	int lift = 0, right = nums.size() - 1;
	for (size_t i = 0; i<nums.size(); i++)
	{
		nums[i] *= nums[i];
	}
	size_t i = ret.size() - 1;
	while (lift <= right)                    //两个指针指向最左端和最右端，将较大的放在ret数组的最后，或者直接放入ret然后反转
	{
		if (nums[lift]<nums[right])
		{
			ret[i] = nums[right];
			right--;
			i--;
		}
		else
		{
			ret[i] = nums[lift];
			lift++;
			i--;
		}
	}
	return ret;

}
void test()
{
	vector<int> v({ -4, -1, 0, 3, 10 });
	vector<int> ret;
	ret = sortedSquares2(v);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}