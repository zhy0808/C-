#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	//����һ��˫ָ�룬�Ӻ���ǰ�����������ո��滻Ϊ%20
	string replaceSpace(string& s)
	{
		int count = 0;            //ͳ�ƿո���
		int lift = s.size() - 1;  //ԭ�ַ������һ��Ԫ�ص�λ��
		for (auto e : s)
		{
			if (e == ' ')
				count++;
		}
		s.resize(s.size() + count * 2);  //��ԭ�ַ������ݵ�������������%20
		int right = s.size() - 1;  //���ݺ�ʵ�ʿռ������һ��λ��
		while (lift >= 0)
		{
			if (s[lift] != ' ')    //���ǿո��ַ�����ƶ�
			{
				s[right] = s[lift];
				right--;
				lift--;
			}
			else                  //��������ո��ں������%20
			{
				s[right--] = '0';
				s[right--] = '2';
				s[right--] = '%';
				lift--;
			}
		}
		return s;
	}
	//�����������ø����ռ���ַ��������޸�
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