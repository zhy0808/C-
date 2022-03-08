#include <iostream>
#include <vector>
using namespace std;

int jumpFloor(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
void test() {
	cout << jumpFloor(7) << endl;
}
int main() {
	test();
	return 0;
}