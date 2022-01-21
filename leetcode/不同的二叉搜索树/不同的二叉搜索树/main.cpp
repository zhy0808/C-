#include <iostream>
#include <vector>
using namespace std;
//dp�����±��ʾ�ڵ���������ݱ�ʾ�е�ǰ��Щ�ڵ�һ��������ɶ��ٶ���������
int numTrees(int n)
{
	vector<int> dp(n + 1);
	dp[0] = 1;
	//���ÿi���ڵ������ɶ��ٸ�����������
	for (int i = 1; i <= n; ++i)
	{
		//��ǰ�������������Է�Ϊ�����������������������������������еĽڵ���ɶ�����������dp����ǰ���Ѿ����������
		//j��1��ʼ������������j-1���ڵ㣬������������i-j���ڵ㣬�������ֽڵ������ɵĶ����������ĸ�����˾��ǵ�ǰ�ڵ������ɶ������������ܸ���

		for (int j = 1; j <= i; ++j)
		{
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}

void test()
{
	cout << numTrees(3) << endl;
}
int main()
{
	test();
	return 0;
}