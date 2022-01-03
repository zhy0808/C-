#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool istrue(string& s, int begin, int end)
{
	if (begin > end)            //检测最后一段时可能出现begin>end的情况
		return false;
	int tmp = end - begin + 1;      //该段有几位
	if (tmp > 3)                //如果该段的位数大于3，不合法
		return false;
	else if (tmp == 3)
	{
		if (s[begin] == '0')    //如果该段有三位，且最高位为0，不合法
			return false;
		if ((s[begin] - '0') * 100 + (s[begin + 1] - '0') * 10 + (s[end] - '0') > 255)  //该段有三位，该段的数字大于255，不合法
			return false;
		return true;
	}
	else if (tmp == 2 && s[begin] == '0')   //该段为两位数，最高位为0，不合法
		return false;
	else
		return true;
}
void find(string& s, vector<string>& ret, int begin, int point)
{ 
	if (point == 3)       //如果已经给s中加入三个'.'了，说明已经分段完成
	{
		if (istrue(s, begin, s.size() - 1))  //检查第4段是否合法
		{
			ret.push_back(s);
		}
		return;
	}
	for (int i = begin; i < s.size(); i++)  //遍历该字符串
	{
		if (istrue(s, begin, i))            //检查当前端是否合法
		{
			s.insert(s.begin() + i + 1, '.');  //当前段如果合法，给当前段后面加上'.'
			find(s, ret, i + 2, point + 1);    //继续找下一个合法的段
			s.erase(s.begin() + i + 1);        //回溯，此时要删掉刚才加的'.'，进入循环继续遍历字符串
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