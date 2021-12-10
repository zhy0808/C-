#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	//法一：暴力解法
	int strStr(string& a, string& b)
	{
		if (b.size() == 0)
			return 0;
		if (a.size() < b.size())
			return -1;
		int bs = b.size();
		for (int i = 0; i + bs <= a.size(); i++)
		{
			if (a[i] == b[0])
			{
				bool flag = true;
				for (int j = i, k = 0; k < b.size(); k++, j++)
				{
					if (a[j] != b[k])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					return i;
			}
		}
		return -1;
	}
	//法二：库函数
	int strStr1(string& a, string& b)
	{
		return a.find(b);
	}
	//法三：KMP算法
	//...
};
void test()
{
	Solution s;
	string str1("hello");
	string str2("ll");
	cout << s.strStr(str1, str2) << endl;
	cout << s.strStr1(str1, str2) << endl;

}
int main()
{
	test();
	return 0;
}