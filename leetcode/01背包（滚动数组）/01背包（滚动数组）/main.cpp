#include <iostream>
#include <vector>
using namespace std;


int bag(vector<int>& weight, vector<int>& val, int bagmax)
{
	//dp�����±��ʾ�������������ݱ�ʾ��ǰ����������װ������ֵ
	vector<int> dp(bagmax + 1, 0);
	//������Ʒ
	for (int i = 0; i < weight.size(); ++i)
	{
		//�Ӵ�С����ֹ�ظ�����ͬһ��Ʒ�������������������㵱ǰ�����ı�������װ����Ʒ������ֵ
		for (int j = bagmax; j >= weight[i]; --j)
		{
			//��ǰ����������װ��Ʒ������ֵҪô�ǲ�װ��i����Ʒ������һ��0-��i-1����Ʒ�е�����ֵ��
			//Ҫô��װ����i����Ʒ����0-i��Ʒ��ѡ��������ֵ
			dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
		}
	}
	return dp[bagmax];
}

void test()
{
	vector<int> weight = { 1,3,4 };
	vector<int> val = { 15,20,30 };
	cout << bag(weight, val, 4) << endl;
}
int main()
{


	test();
	return 0;
}