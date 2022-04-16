#include <iostream>
#include <string>

using namespace std;

void test() {
	string str;
	getline(cin, str);
	int left = 0;
	int right = str.size() - 1;
	while (left < right) {
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
	cout << str << endl;

}
int main() {
	test();
	return 0;
}