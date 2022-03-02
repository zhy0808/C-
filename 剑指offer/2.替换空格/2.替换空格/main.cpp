#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string s){
	string ret;
	for (char c : s) {
		if (c == ' ')
			ret += "%20";
		else
			ret += c;
	}
	return ret;
}
void test(){
	string s = "hello world hhh";
	cout << replaceSpace(s) << endl;
}
int main()
{
	test();
	return 0;
}