#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v = 0)
		:val(v)
		, next(nullptr)
	{

	}
};
class Mylist {
public:
	Mylist() {
		head = new ListNode();
	}
	void Push_front(int v) {
		ListNode* node = new ListNode(v);
		if (head->next != nullptr) {
			ListNode* tmp = head->next;
			head->next = node;
			node->next = tmp;
		}
		else
			head->next = node;
	}
	void print() {
		ListNode* cur = head->next;
		while (cur) {
			cout << cur->val << endl;
			cur = cur->next;
		}
	}
	ListNode* head;
};

ListNode* FindKthToTail(ListNode* head, int k) {
	
	ListNode* cur = head;
	ListNode* ret = head;
	int n = 0;
	while (cur) {
		cur = cur->next;
		n++;
	}
	int m = n - k;
	if (m < 0)
		return nullptr;
	while (m--) {
		ret = ret->next;
	}
	return ret;
	
}
void test() {
	Mylist l;
	l.Push_front(5);
	l.Push_front(4);
	l.Push_front(3);
	l.Push_front(2);
	l.Push_front(1);
	//l.print();
	ListNode* ans = FindKthToTail(l.head->next, 1);
	cout << ans->val << endl;
}
int main() {
	test();
	return 0;
}