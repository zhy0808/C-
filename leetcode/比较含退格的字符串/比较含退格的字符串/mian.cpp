#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
bool backspaceCompare(string s, string t) {
	int i = s.size(), j = t.size();
	int flag1 = 0, flag2 = 0;
	while (i >= 0 || j >= 0)
	{
		while (i >= 0)           //逆序遍历找s串中有效字符的下标
		{
			if (s[i] == '#')     //如果当前字符是#，记录#的次数
			{
				flag1++;
				i--;
			}
			else if (flag1 > 0)  //如果当前字符不是#，但是#还没有用完，就跳到下一个字符
			{
				flag1--;
				i--;
			}
			else                 //如果当前字符不是#，前面的#也用完了，则找到了有效字符
				break;
		}
		while (j >= 0)
		{
			if (t[j] == '#')
			{
				flag2++;
				j--;
			}
			else if (flag2 > 0)
			{
				flag2--;
				j--;
			}
			else
				break;
		}
		if (i >= 0 && j >= 0 && s[i] != t[j])      //两字符串都没遍历完，当前的有效字符不相等
			return false;
		if ((i < 0 && j >= 0) || (i >= 0 && j < 0))//一个字符串遍历完了没找到有效字符，另一个字符串还有有效字符
			return false;
		i--;
		j--;
	}
	return true;
}

int main()
{
	cout << backspaceCompare("ab#c", "b") << endl;
	system("pause");
	return 0;
}