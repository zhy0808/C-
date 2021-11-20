#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	void reverseWords(string& s)
	{
		//快慢指针法去除冗余空格：
		int fast = 0;
		int slow = 0;
		while (s.size() > 0 && fast < s.size() && s[fast] == ' ') //去除头部空格
		{
			fast++;
		}
		for (; fast < s.size(); fast++)  //去除中间冗余空格
		{
			if (fast - 1 > 0 && s[fast - 1] == ' ' && s[fast] == ' ')
				continue;
			else
				s[slow++] = s[fast];
		}
		if (s[slow] == ' ') //去除尾部空格
			slow--;
		s.resize(slow); //更新字符串空间大小

		//反转整个字符串：
		reverse(s.begin(), s.end());

		//反转每个单词
		int lift = 0;
		int right = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				right = i;
				reverse(s.begin() + lift, s.begin() + right);
				lift = i + 1;
			}
			if (i + 1 == s.size())
			{
				reverse(s.begin() + lift, s.end());
			}
		}

	}
};
void test()
{
	Solution s;
	string str(" world hello ");
	s.reverseWords(str);
	cout << str << endl;
}
int main()
{
	test();
	return 0;
}