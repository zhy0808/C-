#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int a1 = a * a;
    int b1 = b * b;
    int c1 = c * c;
    if (a1 == b1 + c1 || b1 == a1 + c1 || c1 == a1 + b1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}