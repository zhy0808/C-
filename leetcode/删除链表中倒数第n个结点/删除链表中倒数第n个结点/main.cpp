#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* Fhead = new ListNode();         //虚拟头节点，防止删除第一个节点时出现头节点要特殊处理
        Fhead->next = head; 
        ListNode* slow = head;                    //快慢指针
        ListNode* fast = head;
        ListNode* prev = Fhead;                   //记录慢指针指向节点的前一个节点
        while (--n)                               //快指针前向后遍历n个节点，保证快指针比满指针快n个位置
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)             //快慢指针同时向后遍历，直到快指针遍历到结尾，此时满指针指向的就是倒数第n个节点
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;                  //删除满指针指向的节点
        head = Fhead->next;
        return head;
    }
};




int main()
{


	return 0;
}