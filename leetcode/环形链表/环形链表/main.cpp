#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x)
		:val(x)
		,next(nullptr)
	{
	}
};
class Solution {
public:
	ListNode* detectCycle(ListNode* head)
	{
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				ListNode* index1 = head;
				ListNode* index2 = fast;
				while (index1 != index2)
				{
					index1 = index1->next;
					index2 = index2->next;
				}
				return index1;
			}
		}
		return nullptr;
	}
};

int main()
{

	return 0;
}