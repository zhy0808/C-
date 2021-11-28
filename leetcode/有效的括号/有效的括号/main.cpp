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
			//�Ƚϵ�ǰ�ַ���ջ���ַ���ASCII�룬'('��')'��ASCII���1��'{'��'}'��'['��']'��ASCII���2
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