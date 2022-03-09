#include <iostream>
#include <vector>
using namespace std;

int jumpFloorII(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] += dp[i - j];
		}
	}
	return dp[n];
}
void test() {
	cout << jumpFloorII(3) << endl;
}
int main() {
	test();
	return 0;
}