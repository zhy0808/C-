#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test1() {
	vector<string> v;
	string s;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		v.push_back(s);
	}
	while (cin >> s) {
		if (s == "quit")
			break;
		v.push_back(s);
	}
	for (string e : v) {
		cout << e << endl;
	}
}
void test() {
	vector<string> nums;
	int n = 0;
	cin >> n;
	//吃掉上面的回车，否则回车会被下面的getline获取
	getchar();
	string in;
	for (int i = 0; i < n; ++i) {
		getline(cin, in);
		nums.push_back(in);
	}
	
	while (cin >> in) {
		if (in == "quit")
			break;
		nums.push_back(in);
	}
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << endl;
		cout << endl;
	}
}
int main() {
	test();
	return 0;
}