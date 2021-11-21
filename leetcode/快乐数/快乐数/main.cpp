#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
	int Sum(int num)               //��������num��ÿһλƽ��֮��
	{
		int ret = 0;
		while (num)
		{
			int a = num % 10;
			ret += a * a;
			num /= 10;
		}
		return ret;
	}
	bool isHappy(int n)
	{
		unordered_set<int> set;
		int sum = n;
		while (1)
		{
			sum = Sum(sum);
			if (sum == 1)             
			{
				return true;
			}
			else if (set.find(sum) != set.end())   //����������set�����ҵ���˵���Ѿ�����ѭ���ˣ�ֱ���˳�
			{
				return false;
			}
			else                              //���set�л�û������ͣ���������set
			{
				set.insert(sum);
			}
		}
	}
};
void test()
{
	Solution s;
	cout << s.isHappy(19) << endl;
}
int main()
{
	test();
	return 0;
}