#include <iostream>
#include <windows.h>
using namespace std;
#include "Stack.hpp"
void test()
{
	zhy::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout << st.top() << endl;
	cout << st.empty() << endl;
	st.pop();
	cout << st.size() << endl;
}
int main()
{
	test();
	system("pause");
	return 0;
}