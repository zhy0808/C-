#include <iostream>
#include <vector>
using namespace std;
int minDistance(string s1, string s2)
{
	//dp[i][j]��ʾs1����i-1Ϊ��β���ַ�����s2����j-1Ϊ��β���ַ���Ҫ�ﵽ�����Ҫɾ���������ַ���
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
	//��s1Ϊ�մ�����s2Ϊ�մ�ʱ����һ���ַ���Ҫ�ﵽ��Ⱦ���Ҫɾ�������ַ�
	for (int i = 0; i <= s1.size(); ++i)
	{
		dp[i][0] = i;
	}
	for (int j = 0; j <= s2.size(); ++j)
	{
		dp[0][j] = j;
	}
	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			//���s1[i - 1]��s[j - 1]��ͬʱ����Ҫ��Ҫɾ���ַ�
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			//�������ͬʱ�������������ɾ��s1�ĵ�i-1���ַ���ɾ��s2�ĵ�j-1���ַ���ͬʱɾ�������ַ�
			else
				dp[i][j] = min(dp[i - 1][j - 1] + 2, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
		}
	}
	return dp[s1.size()][s2.size()];
}
void test()
{
	cout << minDistance("sea", "eat") << endl;
}
int main()
{
	test();
	return 0;
}