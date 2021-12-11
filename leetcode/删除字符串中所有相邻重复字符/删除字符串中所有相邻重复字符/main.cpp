#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
	//法一：使用栈来去除相邻且重复的字符
	string removeDuplicates(string s)
	{
		stack<int> st;
		for (char c : s)
		{
			if (st.empty() || st.top() != c)
				st.push(c);
			else
				st.pop();
		}
		string ret;
		while (st.size())
		{
			ret.push_back(st.top());
			st.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
	//法二：使用字符串模拟栈的操作，删除相邻且重复的字符
	string removeDuplicates1(string s)
	{
		string ret;
		for (char c : s)
		{
			if (ret.empty() || ret.back() != c)
				ret.push_back(c);
			else
				ret.pop_back();
		}
		return ret;
	}
};
void test()
{
	Solution s;
	string str("abbaca");
	cout << s.removeDuplicates(str) << endl;
	cout << s.removeDuplicates1(str) << endl;
}
int main()
{
	test();
	return 0;
}