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
        ListNode* Fhead = new ListNode();         //����ͷ�ڵ㣬��ֹɾ����һ���ڵ�ʱ����ͷ�ڵ�Ҫ���⴦��
        Fhead->next = head; 
        ListNode* slow = head;                    //����ָ��
        ListNode* fast = head;
        ListNode* prev = Fhead;                   //��¼��ָ��ָ��ڵ��ǰһ���ڵ�
        while (--n)                               //��ָ��ǰ������n���ڵ㣬��֤��ָ�����ָ���n��λ��
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)             //����ָ��ͬʱ��������ֱ����ָ���������β����ʱ��ָ��ָ��ľ��ǵ�����n���ڵ�
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;                  //ɾ����ָ��ָ��Ľڵ�
        head = Fhead->next;
        return head;
    }
};




int main()
{


	return 0;
}