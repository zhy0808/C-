#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t)
{
	//dp[i][j]��ʾs��i-1λ��ǰ��t��j-1λ��ǰ�Ĺ�����������󳤶�
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = 1; j <= t.size(); ++j)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	//�����󳤶ȵ���s�ַ����ĳ��ȣ�˵��s��t���ִ�
	if (dp[s.size()][t.size()] == s.size())
		return true;
	else
		return false;
}
void test()
{
	cout << isSubsequence("ace", "asdcfgdce") << endl;
}
int main()
{
	test();
	return 0;
}