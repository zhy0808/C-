#include <iostream>
#include <vector>
using namespace std;
//��������Ϊm��0��n��1��ÿ���ַ���zeroNum��0��oneNum��1
//�����ɸ��ַ�װ�������У���������װ���ٸ��ַ�
//��������Ϊm��0��n��1�������ɸ���Ʒ��ÿ����Ʒ����Ϊzero��0��one��1����ֵ��������Ϊ1
int findMaxForm(vector<string>& strs, int m, int n)
{
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	//��ǰk���ַ�����ѡ���ɸ����뱳�����������Ϊdp[i][j]
	for (string str : strs)
	{
		//��¼ÿ���ַ�������0��1�ĸ��������ַ���������
		int zero = 0, one = 0;
		for (char c : str)
		{
			if (c == '0')
				zero++;
			else
				one++;
		}
		//
		for (int i = m; i >= zero; --i)
		{
			for (int j = n; j >= one; --j)
			{
				dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
			}
		}
	}
	return dp[m][n];
}
void test()
{
	vector<string> strs = { "10", "0001", "111001", "1", "0" };
	cout << findMaxForm(strs, 5, 3) << endl;
}
int main()
{
	test();
	return 0;
}