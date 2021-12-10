#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	//方法一：双指针，从后向前遍历，遇到空格替换为%20
	string replaceSpace(string& s)
	{
		int count = 0;            //统计空格数
		int lift = s.size() - 1;  //原字符串最后一个元素的位置
		for (auto e : s)
		{
			if (e == ' ')
				count++;
		}
		s.resize(s.size() + count * 2);  //将原字符串增容到能容纳下所有%20
		int right = s.size() - 1;  //增容后实际空间中最后一个位置
		while (lift >= 0)
		{
			if (s[lift] != ' ')    //将非空格字符向后移动
			{
				s[right] = s[lift];
				right--;
				lift--;
			}
			else                  //如果遇到空格，在后面插入%20
			{
				s[right--] = '0';
				s[right--] = '2';
				s[right--] = '%';
				lift--;
			}
		}
		return s;
	}
	//方法二：借用辅助空间对字符串进行修改
	string replaceSpace1(string& s)
	{
		string ret;
		for (auto e : s)
		{
			if (e == ' ')
				ret += "%20";
			else
				ret.push_back(e);
		}
		return ret;
	}
	
};
void test()
{
	Solution s;
	string str("We are happy.");
	string s1;
	string s2;
	s1 = s.replaceSpace(str);
	s2 = s.replaceSpace1(str);
	cout << s1 << endl;
	cout << s2 << endl;
}
int main()
{

	test();
	return 0;
}