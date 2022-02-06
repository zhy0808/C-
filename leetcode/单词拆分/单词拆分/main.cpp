#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
//dp�����±����Ҫ��ɵ��ַ����ĳ��ȣ����ݱ�ʾ�������ֵ��еĵ����Ƿ�����ɸ��ַ���
//��Ҫ��ɵ��ַ������������������ֵ��еĵ��ʵ�����Ʒ��ȡ������Ʒ�Ƿ�������װ������

bool wordBreak(string s, vector<string>& wordDict)
{
	//���ֵ�Ž�unordered_set�У�ȥ���Һ������õ�find����	
	unordered_set<string> set(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int j = 1; j <= s.size(); ++j)
	{
		for (int i = 0; i < j; ++i)
		{
			//��ȡ�ַ����е�һ���֣��жϸò����Ƿ����ֵ��еĵ�����ͬ
			string word = s.substr(i, j - i);
			//���ȷ��dp[j] ��true���� [j, i] ���������Ӵ��������ֵ����ôdp[i]һ����true����j < i ����
			if (set.find(word) != set.end() && dp[i] == true)
				dp[j] = true;
		}
	}
	return dp[s.size()];
}
void test()
{
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	cout << wordBreak(s, wordDict) << endl;
}
int main()
{
	test();
	return 0;
}