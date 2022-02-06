#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
//dp数组下标代表要组成的字符串的长度，内容表示用已有字典中的单词是否能组成该字符串
//把要组成的字符串看作背包容量，字典中的单词当作物品，取若干物品是否正好能装满背包

bool wordBreak(string s, vector<string>& wordDict)
{
	//把字典放进unordered_set中，去重且后续会用到find函数	
	unordered_set<string> set(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;

	for (int j = 1; j <= s.size(); ++j)
	{
		for (int i = 0; i < j; ++i)
		{
			//截取字符串中的一部分，判断该部分是否与字典中的单词相同
			string word = s.substr(i, j - i);
			//如果确定dp[j] 是true，且 [j, i] 这个区间的子串出现在字典里，那么dp[i]一定是true。（j < i ）。
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