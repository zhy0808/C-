#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int j = 0, i = 0;
		while (i<pushV.size())
		{
			s.push(pushV[i]);
			i++;
			while (!s.empty() && s.top() == popV[j])   //栈如果是空的就不能进行pop操作
			{
				s.pop();
				j++;
			}
		}

		return s.empty();
	}
};

void test()
{
	stack<int> s;
	/*s.push(1);
	s.pop();*/
	cout << s.top() << endl;
}
int main()
{
	//test();
	Solution a;
	vector<int> v1({ 1, 2, 3, 4, 5 });
	vector<int> v2({ 1, 2, 3, 4, 5 });
    a.IsPopOrder(v1, v2);
	system("pause");
	return 0;
}