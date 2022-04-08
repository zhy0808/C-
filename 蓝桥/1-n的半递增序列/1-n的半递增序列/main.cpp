#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int f[1010];
    int n;
    cin >> n;
    int k = n / 2;
    for (int i = 1; i <= n; i++) {
        f[0] = 1;
        f[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            f[j] = (f[j - 1] + f[j]) % (int)(1e9 + 7);
        }
    }
    cout << f[k] << endl;
    return 0;
}