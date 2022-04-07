#include <iostream>

using namespace std;

void test() {
	int n = 0;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		int j;
		for (j = 2; j < i; ++j) {
			if (i % j == 0)
				break;
		}
		if (j == i)
			cout << i << endl;
	}
}
int main() {
	test();
	return 0;
}