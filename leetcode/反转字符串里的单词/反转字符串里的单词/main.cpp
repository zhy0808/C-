#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	void reverseWords(string& s)
	{
		//����ָ�뷨ȥ������ո�
		int fast = 0;
		int slow = 0;
		while (s.size() > 0 && fast < s.size() && s[fast] == ' ') //ȥ��ͷ���ո�
		{
			fast++;
		}
		for (; fast < s.size(); fast++)  //ȥ���м�����ո�
		{
			if (fast - 1 > 0 && s[fast - 1] == ' ' && s[fast] == ' ')
				continue;
			else
				s[slow++] = s[fast];
		}
		if (s[slow] == ' ') //ȥ��β���ո�
			slow--;
		s.resize(slow); //�����ַ����ռ��С

		//��ת�����ַ�����
		reverse(s.begin(), s.end());

		//��תÿ������
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