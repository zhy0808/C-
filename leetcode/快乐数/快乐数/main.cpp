#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
	int Sum(int num)               //计算整数num的每一位平方之和
	{
		int ret = 0;
		while (num)
		{
			int a = num % 10;
			ret += a * a;
			num /= 10;
		}
		return ret;
	}
	bool isHappy(int n)
	{
		unordered_set<int> set;
		int sum = n;
		while (1)
		{
			sum = Sum(sum);
			if (sum == 1)             
			{
				return true;
			}
			else if (set.find(sum) != set.end())   //如果这个和在set中能找到，说明已经进入循环了，直接退出
			{
				return false;
			}
			else                              //如果set中还没有这个和，把他存入set
			{
				set.insert(sum);
			}
		}
	}
};
void test()
{
	Solution s;
	cout << s.isHappy(19) << endl;
}
int main()
{
	test();
	return 0;
}