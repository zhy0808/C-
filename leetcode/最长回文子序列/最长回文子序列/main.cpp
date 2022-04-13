#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromeSubseq(string s) {
	//dp[i][j]表示s中下标i到下标j中最长回文子序列的长度
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	//每一个字符最长序列就是1
	for (int i = 0; i < s.size(); ++i) {
		dp[i][i] = 1;
	}
	for (int i = s.size() - 1; i >= 0; --i) {
		for (int j = i + 1; j < s.size(); ++j) {
			//如果下标为i的字符和下标为j的字符相等，如果两字符相邻，则他们间的最长回文子序列为2
			//如果两字符不相邻，则他们下标间的最长回文子序列为中间夹得字符串的最长回文子序列加2
			if (s[i] == s[j]) {
				if (i == j - 1)
					dp[i][j] = 2;
				else
					dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			//如果两字符不相等，则他们下标间最长回文子序列长度为i—j-1之间的最大值和i+1—j之间的最大值的最大值
			else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][s.size() - 1];

}
void test() {
	cout << longestPalindromeSubseq("bbbbab") << endl;
}
int main() {
	test();
	return 0;
}