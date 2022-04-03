#include <iostream>
#include <windows.h>
#include "Queue.h"

using namespace std;
void test()
{
	zhy::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.empty() << endl;
	cout << q.size() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.empty() << endl;
	cout << q.size() << endl;


}

int main()
{
	test();
	system("pause");
	return 0;
}