#include <iostream>
#include <list>
#include <vector>
using namespace std;

//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode(int _val = 0, ListNode* _next = nullptr)
//		:val(_val)
//		, next(_next)
//	{
//	}
//};
//void push_back(ListNode* tail, int val)
//{
//	ListNode* newnode = new ListNode(val);
//	tail->next = newnode;
//	cout << "push_back" << endl;
//}
//void test()
//{
//	ListNode* head = new ListNode(1);
//	push_back(head, 8);
//	ListNode* cur = head;
//	while (cur != nullptr)
//	{
//		cout << cur->val << endl;
//		cur = cur->next;
//	}
//}

void removeelements(list<int>& l, int val)
{
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it == val)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
}
void test()
{
	vector<int> v = { 1,2,6,3,4,5,6 };
	list<int> l(v.begin(), v.end());
	removeelements(l, 6);
	list<int>::iterator it = l.begin();
	while(it!=l.end())
	{
		cout << *it << endl;
		it++;
	}
}
int main()
{
	test();
	return 0;
}