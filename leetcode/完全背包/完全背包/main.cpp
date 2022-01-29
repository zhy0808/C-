#include <iostream>
#include <vector>
using namespace std;
//��01�����е��ű���������Ϊ˳��������ɣ����ű�������Ϊ�˷�ֹ��Ʒ�ظ�����ȫ��������Ʒ�����ظ�
int CompletePack(vector<int>& weight, vector<int>& val, int bagmax)
{
	vector<int> dp(bagmax + 1, 0);
	for (int i = 0; i < weight.size(); ++i)
	{
		for (int j = weight[i]; j <= bagmax; ++j)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
		}
	}
	return dp[bagmax];
}
void test()
{
	vector<int> weight = { 1,3,4 };
	vector<int> val = { 15,20,30 };
	cout << CompletePack(weight, val, 4) << endl;
}
int main()
{
	test();
	return 0;
}