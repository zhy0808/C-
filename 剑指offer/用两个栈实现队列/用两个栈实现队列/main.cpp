#include <iostream>
#include <stack>
using namespace std;


class My_queue {
public:
	void push(int v) {
		s1.push(v);
	}
	int pop() {
		if (s1.size() == 0) {
			return 0;
		}
		while (s1.size()) {
			s2.push(s1.top());
			s1.pop();
		}
		int ret = s2.top();
		s2.pop();
		while (s2.size()) {
			s1.push(s2.top());
			s2.pop();
		}
		return ret;
	}


private:
	stack<int> s1;
	stack<int> s2;
};
void test() {
	My_queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.pop() << endl;
}
int main()
{
	test();
	return 0;
}