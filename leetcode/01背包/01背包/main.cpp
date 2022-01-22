#include <iostream>
#include <vector>
using namespace std;

int bag(vector<int>& weight, vector<int>& val, int bagmax)
{
	//dp�����±�i�����i����Ʒ��j������������dp[i][j]����������Ϊjʱ������Ʒ0-i������ȡ��Ʒ���Եõ�������ֵ
	vector<vector<int>> dp(weight.size(), vector<int>(bagmax + 1, 0));
	//�ȳ�ʼ��������������0-max��װ��һ����Ʒ�ĵõ����ܼ�ֵ����Ϊ����������Ҫ����װ��һ����Ʒ���ܼ�ֵ
	for (int j = 0; j < bagmax; ++j)
	{
		//�����ǰ��������С�ڵ�һ����Ʒ������������װ����ȥ�������������ӱ���������
		//�����װ��ȥ���Ͱ�dp�����Ӧλ�õ�ֵ��Ϊ��һ����Ʒ�ļ�ֵ
		if (j >= weight[0])
			dp[0][j] = val[0];
	}
	//����������Ϊjʱ�������i����Ʒȡ������õ�������ֵ
	for (int i = 1; i < weight.size(); ++i)
	{
		for (int j = 0; j <= bagmax; ++j)
		{
			//�����ǰ��������С�ڵ�i����Ʒ��������˵��װ���µ�i����������ֵΪ��0-��i-1������ѡ�����������ֵ
			if (j < weight[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			//�����ǰ����������װ�µ�i����Ʒ����Ƚ���0-i����װ��i����Ʒ�������ֵ�Ͳ�װ��i����Ʒ������ֵ��ȡ����ֵ
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + val[i]);
			}
		}
	}
	return dp[weight.size() - 1][bagmax];
}

void test()
{
	vector<int> weight = { 1, 3, 4 };
	vector<int> val = { 15, 20, 30 };
	cout << bag(weight, val, 4) << endl;
}
int main()
{

	test();
	return 0;
}