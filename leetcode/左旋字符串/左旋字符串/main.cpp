#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	void reverseLiftString(string& s, int n)
	{
		reverse(s.begin(), s.end());
		reverse(s.begin(), s.begin() + (s.size() - n));
		reverse(s.begin() + (s.size() - n), s.end());
	}
};
void test()
{
	Solution s;
	string str("abcdefg");
	s.reverseLiftString(str, 2);
	cout << str << endl;
}
int main()
{
	test();
	return 0;
}