#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		for (string e : tokens)
		{
			if (e != "+" && e != "-" && e != "*" && e != "/")  //如果当前元素是数字，则入栈
			{
				st.push(atoi(e.c_str()));
			}
			else                         //如果当前元素是运算符，则出栈两个数字进行运算，将结果入栈
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int res = 0;
				if (e == "+")
					res = a + b;
				else if (e == "-")
					res = b - a;                   //减法和除法要注意做运算时数字的次序
				else if (e == "*")
					res = a * b;
				else if (e == "/")
					res = b / a;
				st.push(res);
			}
		}
		return st.top();
	}
};
void test()
{
	Solution s;
	vector<string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	cout << s.evalRPN(tokens) << endl;
}
int main()
{
	test();
	return 0;
}