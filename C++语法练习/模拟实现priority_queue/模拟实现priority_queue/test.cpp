#include <iostream>
#include <windows.h>
#include "Priority_queue.h"
using namespace std;


void test()
{
	zhy::priority_queue<int, vector<int>, Greater<int>> pq;  //С����
	//zhy::priority_queue<int> pq;  Ĭ��Ϊ�����
	pq.push(1);
	pq.push(5);
	pq.push(3);
	pq.push(0);
	pq.push(6);
	pq.push(3);
	while (pq.size())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}

namespace Test
{
	template<class T>
	class Compare
	{
	public:
		void operator()(const T& a, const T& b)
		{
			if (a > b)
				cout << a << ">" << b << endl;
			else if (a < b)
				cout << a << "<" << b << endl;
			else
				cout << a << "=" << b << endl;
		}
	};
	void test()
	{
		Compare<int> com;
		com(2, 3);
		com(1, 1);
		com(9, 1);
	}
}
int main()
{
	//test();
	Test::test();
	system("pause");
	return 0;
}