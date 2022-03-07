#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int n) {
	vector<int> dp(n, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n - 1];
}
void test() {
	cout << Fibonacci(4) << endl;
}
int main() {
	test();
	return 0;
}