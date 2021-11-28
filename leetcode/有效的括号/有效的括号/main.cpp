#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	bool isValid(string s)
	{
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			//比较当前字符和栈顶字符的ASCII码，'('和')'的ASCII码差1，'{'和'}'、'['和']'的ASCII码差2
			if (!st.empty() && (s[i] - 1 == st.top() || s[i] - 2 == st.top()))
			{
				st.pop();
			}
			else
				st.push(s[i]);
		}
		return st.empty();
	}
};
void test()
{
	Solution s;
	string str("()");
	cout << s.isValid(str) << endl;


}
int main()
{
	test();
	return 0;
}