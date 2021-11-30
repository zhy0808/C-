#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        int size = s.size();
        while (size--)         //将x入队前的数据暂存再tmp中
        {
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);            //将x入栈
        int size1 = tmp.size();
        while (size1--)       //将暂存再tmp中的数据拿回来，保证x最后一个出栈
        {
            s.push(tmp.top());
            tmp.pop();
        }

    }

    int pop() {
        int ret = s.top();
        s.pop();
        return ret;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        if (s.empty())
            return true;
        else
            return false;
    }

private:
    stack<int> s;
    stack<int> tmp;
};

void test()
{
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.push(4);
    mq.push(5);
    cout << mq.peek() << endl;

}
int main()
{
    test();
	return 0;
}