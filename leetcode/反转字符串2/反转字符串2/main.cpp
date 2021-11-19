#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseString(string& s, int k)
	{
		int lift = 0;
		int right = lift + k - 1;
		while (lift < s.size()-1)
		{
			if (right > s.size() - 1)    //如果新区间不够k个元素，逆置剩下所有的元素
			{
				reverse(s.begin() + lift, s.end());
				break;
			}
			reverse(s.begin() + lift, s.begin() + right + 1);  //逆置k个元素，reverse逆置是左闭右开区间，所以右边界要+1
			lift += 2 * k;   //更新到下一个2k区间
			right += 2 * k;
		}
	}
};
void test()
{
	Solution s;
	string str("abcdefg");
	s.reverseString(str, 6);
	cout << str << endl;
}
int main()
{
	test();
	return 0;
}