#include <iostream>
#include <vector>
using namespace std;
//dp�����±����Ҫ��ɵ��������ݴ���Ҫ��ɸ���������Ҫ������ȫƽ����
int numSquares(int n)
{
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	//����Ҫ�������С��Ҫ�ĸ����������ȱ�����Ʒ����ϣ������ȱ������������У��Ը���û��Ӱ��
	for (int i = 1; i * i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (j >= i * i)
				dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}
	return dp[n];
}
void test()
{
	cout << numSquares(10) << endl;
}
int main()
{

	test();
	return 0;
}