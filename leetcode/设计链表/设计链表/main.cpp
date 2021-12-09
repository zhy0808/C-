#include <iostream>
using namespace std;

class MyLinkedList {
public:
    typedef struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int _val = 0, Node* _next = nullptr, Node* _prev = nullptr)
            :val(_val)
            , next(_next)
            , prev(_prev)
        {}
    }Node;
    MyLinkedList() {
        _size = 0;
        _head = new Node();
        _head->next = _head;
        _head->prev = _head;
    }

    int get(int index) {
        int ret = 0;
        if (index >= _size)
            ret = -1;
        else
        {
            Node* cur = _head;
            for (int i = 0; i <= index; i++)
            {
                cur = cur->next;
            }
            ret = cur->val;
        }
        return ret;
    }

    void addAtHead(int val) {
        Node* newnode = new Node(val);
        Node* head = _head->next;
        _head->next = newnode;
        newnode->prev = _head;
        head->prev = newnode;
        newnode->next = head;
        _size++;
    }

    void addAtTail(int val) {
        Node* newnode = new Node(val);
        Node* tail = _head->prev;
        newnode->prev = tail;
        tail->next = newnode;
        _head->prev = newnode;
        newnode->next = _head;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size)
        {

        }
        else if (index == _size)
        {
            addAtTail(val);
        }
        else if (index <= 0)
        {
            addAtHead(val);
        }
        else
        {
            Node* cur = _head;
            for (int i = 0; i <= index; i++)
            {
                cur = cur->next;
            }
            Node* p = cur->prev;
            Node* newnode = new Node(val);
            newnode->next = cur;
            cur->prev = newnode;
            p->next = newnode;
            newnode->prev = p;
            _size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= 0 && index < _size)
        {
            Node* cur = _head;
            for (int i = 0; i <= index; i++)
            {
                cur = cur->next;
            }
            Node* p = cur->prev;
            p->next = cur->next;
            cur->next->prev = p;

            _size--;
        }
    }
    void Print()
    {
        Node* cur = _head;
        for (int i = 0; i < _size; i++)
        {
            cur = cur->next;
            cout << cur->val << "_size:" << _size << endl;
        }
    }
private:
    Node* _head;
    int _size;

};

void test()
{
    MyLinkedList ml;
    ml.addAtHead(7);
    ml.addAtHead(2);
    ml.addAtHead(1);
    ml.addAtIndex(3, 3);
    ml.deleteAtIndex(2);
    ml.addAtHead(6);
    ml.addAtTail(4);
    ml.addAtTail(5);
    ml.addAtIndex(3, 0);
    ml.Print();
    cout << ml.get(4) << endl;
    cout << ml.get(6) << endl;
    cout << sizeof("asd") << endl;
}
int main()
{

    test();
    return 0;
}