#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v = 0) 
		:val(v)
		,next(nullptr)
	{

	}
};
class mylist {
public:
	mylist() {
		head = new ListNode();
	}
	void Push_front(int v) {
		ListNode* node = new ListNode(v);
		if (head->next == nullptr)
			head->next = node;
		else {
			ListNode* tmp = head->next;
			head->next = node;
			node->next = tmp;
		}
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
ListNode* Reverse(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* cur = head;
	ListNode* prev = nullptr;
	while (cur) {
		ListNode* tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;
}
void print(ListNode* ans) {
	ListNode* cur = ans;
	while (cur) {
		cout << cur->val << endl;
		cur = cur->next;
	}
}
void test() {
	mylist l;
	cout << "reverse begin:" << endl;
	l.Push_front(5);
	l.Push_front(4);
	l.Push_front(3);
	l.Push_front(2);
	l.Push_front(1);
	l.print();
	cout << "reverse after:" << endl;
	ListNode* ans = Reverse(l.head->next);
	print(ans);
}
int main() {
	test();
	return 0;
}