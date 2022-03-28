#include <iostream>
#include <vector>
using namespace std;

int cutRope(int n) {
	if (n <= 3)
		return n - 1;
	//dp[i]表示长度为i的绳子分割后的最大乘积
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			dp[i] = max(dp[i], dp[j] * dp[i - j]);
		}
	}
	return dp[n];
}
void test() {
	cout << cutRope(8) << endl;
}
int main() {
	test();
	return 0;
}