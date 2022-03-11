#include <iostream>
#include <vector>
using namespace std;
void reOrderArray(vector<int>& n) {
	for (int i = 0; i < n.size(); ++i) {
		for (int j = n.size() - 1; j > i; --j) {
			if (n[j] % 2 == 1 && n[j - 1] % 2 == 0) {
				swap(n[j], n[j - 1]);
			}
		}
	}
}
void test() {
	vector<int> n = { 1,2,3,4,5,6,7 };
	reOrderArray(n);
	for (int e : n) {
		cout << e;
	}
	cout << endl;
}
int main() {
	test();
	return 0;
}