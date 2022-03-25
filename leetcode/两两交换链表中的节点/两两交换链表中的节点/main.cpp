#include <iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v = 0, ListNode* n = nullptr)
		:val(v)
		, next(nullptr) {

	}
};
class Mylist {
public:
	Mylist() {
		head = new ListNode();
	}
	void push(int v) {
		ListNode* node = new ListNode(v);
		node->next = head->next;
		head->next = node;
	}
	ListNode* gethead() {
		return head->next;
	}
private:
	ListNode* head;
};
ListNode* swapPairs(ListNode* head) {
	if (head == nullptr)
		return head;
	ListNode* h = new ListNode();
	h->next = head;
	ListNode* prev = h;
	ListNode* left = head;
	ListNode* right = head->next;
	while (left->next) {
		ListNode* tmp = right->next;
		right->next = left;
		left->next = tmp;
		prev->next = right;
		if (left->next == nullptr || left->next->next)
			break;
		prev = left;
		left = left->next;
		right = left->next;
	}
	return h->next;
}
void print(ListNode* cur) {
	while (cur) {
		cout << cur->val << endl;
		cur = cur->next;
	}
}
void test() {
	Mylist l;
	l.push(4);
	l.push(3);
	l.push(2);
	l.push(1);
	ListNode* ret = swapPairs(l.gethead());
	print(ret);
}
int main() {
	test();
	return 0;
}