#include <iostream>
#include <vector>
using namespace std;

int func(int a) {
	if (a <= 3)
		return a;
	vector<int> dp(a + 1, 0);
	//dp[i]表示第i年的母牛总数
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= a; ++i) {
		//第i年的母牛数等于前一年的母牛数加老母牛生出的母牛，老母牛是三年前所有的母牛数
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	return dp[a];
}
void test() {
	int a = 0;
	while (cin >> a) {
		if (a == 0)
			break;
		cout << func(a) << endl;
	}
}
int main() {
	test();
	return 0;
}