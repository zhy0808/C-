#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    //Ë«Ö¸Õë
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* flag = head;
        while (cur != nullptr)
        {
            flag = flag->next;
            cur->next = prev;
            prev = cur;
            cur = flag;
        }
        head = prev;
        return head;
    }
    //µİ¹é
    ListNode* reserve(ListNode* prev, ListNode* cur)
    {
        if (cur == nullptr)
            return prev;
        ListNode* flag = cur->next;
        cur->next = prev;
        return reserve(cur, flag);
    }
    ListNode* rL(ListNode* head)
    {
        return reserve(nullptr, head);
    }
};











int main()
{


	return 0;
}