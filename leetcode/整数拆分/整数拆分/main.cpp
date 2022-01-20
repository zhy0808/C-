#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n)
{
	vector<int> dp(n + 1);
	dp[2] = 1;//1��0�����ܲ�֣��ʲ��ó�ʼ��1��0λ��
	for (int i = 3; i <= n; ++i)//����i���Բ�ֺ�˻������ֵ�������dp[i]��
	{
		for (int j = 1; j < i; ++j)//���j��i-j
		{
			//p[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
			//���ֵ�����������
			//1.��ֳɶ��������j*dp[i-j]��dp[i-j]���ǰ�i-j��ֳɶ�����˻������ֵ��j�����ٲ𣬱����Ĺ��̾Ͱ���������������
			if (dp[i - j] > i - j)
				dp[i] = max(dp[i], dp[i - j] * j);
			//2.��ֳ���������j*i-j��������������ڲ���Ȳ����ٳ˵�ֵ��
			else
				dp[i] = max(dp[i], (i - j) * j);
		}
	}
	return dp[n];
}
void test()
{
	cout << integerBreak(10) << endl;
}
int main()
{
	test();
	return 0;
}