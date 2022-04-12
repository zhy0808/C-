#include <iostream>
#include <vector> 
#include <string>
using namespace std;

int numDistinct(string s, string t) {
	if (s.size() < t.size()) {
		return 0;
	}
	//dp[i][j]��ʾs��ǰi - 1�±���ַ������������ж��ٸ�t��ǰj - 1�±���ַ�
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 0; i < dp.size(); ++i) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 1; j <= t.size(); ++j) {
			if (s[i - 1] == t[j - 1]) {
				//�û��߲���s�е�i-1���ַ�
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
				//����s�е�i - 1���ַ�
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