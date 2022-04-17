#include <iostream>
using namespace std;
int main()
{
    int p = 0;
    int t = 0;
    cin >> p >> t;
    int count = t / 12;
    int flag = t % 12;
    if (flag > 0)
        count++;
    cout << count * p << endl;
    return 0;
}