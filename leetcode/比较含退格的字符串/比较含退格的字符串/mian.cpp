#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
bool backspaceCompare(string s, string t) {
	int i = s.size(), j = t.size();
	int flag1 = 0, flag2 = 0;
	while (i >= 0 || j >= 0)
	{
		while (i >= 0)           //���������s������Ч�ַ����±�
		{
			if (s[i] == '#')     //�����ǰ�ַ���#����¼#�Ĵ���
			{
				flag1++;
				i--;
			}
			else if (flag1 > 0)  //�����ǰ�ַ�����#������#��û�����꣬��������һ���ַ�
			{
				flag1--;
				i--;
			}
			else                 //�����ǰ�ַ�����#��ǰ���#Ҳ�����ˣ����ҵ�����Ч�ַ�
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
		if (i >= 0 && j >= 0 && s[i] != t[j])      //���ַ�����û�����꣬��ǰ����Ч�ַ������
			return false;
		if ((i < 0 && j >= 0) || (i >= 0 && j < 0))//һ���ַ�����������û�ҵ���Ч�ַ�����һ���ַ���������Ч�ַ�
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