#include <iostream>
#include <vector>

using namespace std;

const int N = 100010;

int main()
{
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    int min1 = N, max1 = 0, min2 = N, max2 = 0;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == a[i]) cnt++;
        else {
            min1 = min(min1, i);
            max1 = max(max1, i);
            min2 = min(min2, a[i]);
            max2 = max(max2, a[i]);
            if (min1 == min2 && max1 == max2) {
                cnt++;
                min1 = N, max1 = 0, min2 = N, max2 = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}