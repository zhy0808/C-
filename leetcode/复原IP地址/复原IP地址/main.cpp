#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool istrue(string& s, int begin, int end)
{
	if (begin > end)            //������һ��ʱ���ܳ���begin>end�����
		return false;
	int tmp = end - begin + 1;      //�ö��м�λ
	if (tmp > 3)                //����öε�λ������3�����Ϸ�
		return false;
	else if (tmp == 3)
	{
		if (s[begin] == '0')    //����ö�����λ�������λΪ0�����Ϸ�
			return false;
		if ((s[begin] - '0') * 100 + (s[begin + 1] - '0') * 10 + (s[end] - '0') > 255)  //�ö�����λ���öε����ִ���255�����Ϸ�
			return false;
		return true;
	}
	else if (tmp == 2 && s[begin] == '0')   //�ö�Ϊ��λ�������λΪ0�����Ϸ�
		return false;
	else
		return true;
}
void find(string& s, vector<string>& ret, int begin, int point)
{ 
	if (point == 3)       //����Ѿ���s�м�������'.'�ˣ�˵���Ѿ��ֶ����
	{
		if (istrue(s, begin, s.size() - 1))  //����4���Ƿ�Ϸ�
		{
			ret.push_back(s);
		}
		return;
	}
	for (int i = begin; i < s.size(); i++)  //�������ַ���
	{
		if (istrue(s, begin, i))            //��鵱ǰ���Ƿ�Ϸ�
		{
			s.insert(s.begin() + i + 1, '.');  //��ǰ������Ϸ�������ǰ�κ������'.'
			find(s, ret, i + 2, point + 1);    //��������һ���Ϸ��Ķ�
			s.erase(s.begin() + i + 1);        //���ݣ���ʱҪɾ���ղżӵ�'.'������ѭ�����������ַ���
		}
		else
			break;
	}
}
vector<string> restoreIpAddresses(string s)
{
	vector<string> ret;
	if (s.size() > 12)
		return ret;
	find(s, ret, 0, 0);
	return ret;
}


void test()
{
	vector<string> ret;
	ret = restoreIpAddresses("101023");
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}
}
int main()
{

	test();
	return 0;
}