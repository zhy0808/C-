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
    //�����������ߵĴ������������ߵĴ������ܳ��� 1��
    //���Ե�����Ϊż��ʱ��������������Ϊ��n/2���͵�n/2 + 1������Ϊ�±��Ǵ�0��ʼ�ģ��������±��ʾʱҪ��1
    //����Ϊ����ʱ��������������Ϊ��n/2 + 1��
    if (size % 2 == 0)
        cout << max(dp[size - 1][size / 2 - 1], dp[size - 1][size / 2]) << endl;
    else
        cout << dp[size - 1][size / 2] << endl;
    return 0;
}