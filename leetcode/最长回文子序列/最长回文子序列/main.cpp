#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestPalindromeSubseq(string s) {
	//dp[i][j]��ʾs���±�i���±�j������������еĳ���
	vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
	//ÿһ���ַ�����о���1
	for (int i = 0; i < s.size(); ++i) {
		dp[i][i] = 1;
	}
	for (int i = s.size() - 1; i >= 0; --i) {
		for (int j = i + 1; j < s.size(); ++j) {
			//����±�Ϊi���ַ����±�Ϊj���ַ���ȣ�������ַ����ڣ������Ǽ�������������Ϊ2
			//������ַ������ڣ��������±��������������Ϊ�м�е��ַ���������������м�2
			if (s[i] == s[j]) {
				if (i == j - 1)
					dp[i][j] = 2;
				else
					dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			//������ַ�����ȣ��������±������������г���Ϊi��j-1֮������ֵ��i+1��j֮������ֵ�����ֵ
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