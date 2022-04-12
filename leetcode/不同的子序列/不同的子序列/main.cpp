#include <iostream>
#include <vector> 
#include <string>
using namespace std;

int numDistinct(string s, string t) {
	if (s.size() < t.size()) {
		return 0;
	}
	//dp[i][j]表示s的前i - 1下标个字符的子序列中有多少个t的前j - 1下标个字符
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 0; i < dp.size(); ++i) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 1; j <= t.size(); ++j) {
			if (s[i - 1] == t[j - 1]) {
				//用或者不用s中第i-1个字符
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
				//不用s中第i - 1个字符
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[s.size()][t.size()];
}
void test() {
	cout << numDistinct("rabbbit", "rabbit") << endl;
}
int main() {
	test();
	return 0;
}