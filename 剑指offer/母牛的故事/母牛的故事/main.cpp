#include <iostream>
#include <vector>
using namespace std;

int func(int a) {
	if (a <= 3)
		return a;
	vector<int> dp(a + 1, 0);
	//dp[i]��ʾ��i���ĸţ����
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= a; ++i) {
		//��i���ĸţ������ǰһ���ĸţ������ĸţ������ĸţ����ĸţ������ǰ���е�ĸţ��
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