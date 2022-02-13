#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int size = 0;
    cin >> size;
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
                dp[i][j] += dp[i - 1][j];
            else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    //由于向左下走的次数与向右下走的次数相差不能超过 1。
    //所以当行数为偶数时，符合条件的数为第n/2个和第n/2 + 1个，因为下标是从0开始的，所以用下标表示时要减1
    //行数为奇数时，符合条件的数为第n/2 + 1个
    if (size % 2 == 0)
        cout << max(dp[size - 1][size / 2 - 1], dp[size - 1][size / 2]) << endl;
    else
        cout << dp[size - 1][size / 2] << endl;
    return 0;
}