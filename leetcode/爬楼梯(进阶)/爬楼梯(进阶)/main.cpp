#include <iostream>
#include <vector>
using namespace std;
//һ��һ��̨�ף�����̨�ף�����̨��,ֱ�� n��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
//̨��������Ϊ����������ÿ�ο����ϵĽ���Ϊ��Ʒ����������������ж����ַ���

int climbStairs(int n)
{
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int j = 1; j <= n; ++j)
	{
		for (int i = 1; i <= j; ++i)
		{
			dp[j] += dp[j - i];
		}
	}
	return dp[n];
}
void test()
{
	cout << climbStairs(3) << endl;
}
int main()
{
	test();
	return 0;
}