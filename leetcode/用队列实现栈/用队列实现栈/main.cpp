#include <iostream>
#include <queue>
using namespace std;
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int size = q.size() - 1;
        while (size--)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int ret = q.front();
        q.pop();
        return ret;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};
void test()
{
    MyStack ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);
    cout << ms.top() << endl;

}
int main()
{
    test();
	return 0;
}