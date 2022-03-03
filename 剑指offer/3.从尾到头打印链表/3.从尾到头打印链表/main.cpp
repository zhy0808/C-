#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v = 0)
		:val(v)
		, next(nullptr) {

	}
};
class list {
public:
	list()
		:head(nullptr)
	{

	}
	void push(int a) {
		ListNode* newNode = new ListNode(a);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			ListNode* tmp = head;
			head = newNode;
			head->next = tmp;
		}

		
	}
	ListNode* getHead() {
		return head;
	}


private:
	ListNode* head;
};
vector<int> printListFromTailToHead(ListNode* head) {
	ListNode* cur = head;
	vector<int> ret;
	while (cur) {
		ret.push_back(cur->val);
		cur = cur->next;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
void test() {
	list l;
	l.push(3);
	l.push(2);
	l.push(1);
	vector<int> nums;
	nums = printListFromTailToHead(l.getHead());
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << endl;
	}
}
int main(){
	test();
	return 0;
}
