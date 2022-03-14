#include <iostream>

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
class mylist {
public:
	mylist() {
		head = new ListNode();
	}
	void Push_front(int n) {
		ListNode* node = new ListNode(n);
		if (head->next == nullptr)
			head->next = node;
		else {
			ListNode* tmp = head->next;
			head->next = node;
			node->next = tmp;
		}
	}

	ListNode* head;
};
ListNode* Merge(ListNode* h1, ListNode* h2) {
	ListNode* rethead = new ListNode();
	ListNode* tmp = rethead;
	ListNode* cur1 = h1;
	ListNode* cur2 = h2;
	while (cur1 && cur2) {
		if (cur1->val < cur2->val) {
			tmp->next = cur1;
			cur1 = cur1->next;
		}
		else {
			tmp->next = cur2;
			cur2 = cur2->next;
		}
		tmp = tmp->next;
	}
	if (cur1 == nullptr)
		tmp->next = cur2;
	else
		tmp->next = cur1;
	return rethead->next;
}
void print(ListNode* head) {
	ListNode* cur = head;
	while (cur) {
		cout << cur->val << endl;
		cur = cur->next;
	}
}
void test() {
	mylist l1;
	mylist l2;
	l1.Push_front(6);
	l1.Push_front(4);
	l1.Push_front(2);
	l2.Push_front(5);
	l2.Push_front(3);
	l2.Push_front(1);
	ListNode* ans = Merge(l1.head->next, l2.head->next);
	print(ans);
}
int main() {
	test();
	return 0;
}