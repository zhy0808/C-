#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
	if (s.size() == 0)
		return 0;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int j = s.size() - 1;
	int ret = 0;
	for (int i = g.size() - 1; i >= 0; --i) {
		if (j >= 0 && s[j] >= g[i]) {
			ret++;
			j--;
		}
	}
	return ret;
}
void test() {
	vector<int> g = { 1,2,3 };
	vector<int> s = { 1,2,3 };
	cout << findContentChildren(g, s) << endl;
}
int main() {
	test();
	return 0;
}