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
			if (e != "+" && e != "-" && e != "*" && e != "/")  //�����ǰԪ�������֣�����ջ
			{
				st.push(atoi(e.c_str()));
			}
			else                         //�����ǰԪ��������������ջ�������ֽ������㣬�������ջ
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				int res = 0;
				if (e == "+")
					res = a + b;
				else if (e == "-")
					res = b - a;                   //�����ͳ���Ҫע��������ʱ���ֵĴ���
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