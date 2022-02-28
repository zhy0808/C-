#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s){
	//dp[i][j]表示s中第i个到第j个字符串是否为回文串
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	int ret = 0;
	for (int i = s.size() - 1; i >= 0; --i){
		for (int j = i; j < s.size(); ++j){
			//如果第i个和第j个不同，不需要处理，初始化就是false
			//如果相同，有三种情况是回文串：1、i和j指向同一字符；2、i和j指向相邻字符；3、i和j中间还有字符，且中间字符串是回文串
			if (s[i] == s[j]) {
				if (j - i <= 1){
					ret++;
					dp[i][j] = true;
				}
				else if (dp[i + 1][j - 1]) {
					ret++;
					dp[i][j] = true;
				}
			}
		}
	}
	return ret;
}
void test()
{
	cout << countSubstrings("aaaaa") << endl;
}
int main()
{
	test();
	return 0;
}