#include <iostream>
#include <vector>
using namespace std;
int findLength(vector<int>& A, vector<int>& B)
{
	//dp[i][j]表示A[i-1]和B[j-1]前最长重复子数组的长度
	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
	int ret = 0;
	for (int i = 1; i <= A.size(); ++i)
	{
		for (int j = 1; j <= B.size(); ++j)
		{
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			if (ret < dp[i][j])
				ret = dp[i][j];
		}
	}
	return ret;
}
void test()
{
	vector<int> A = { 1,2,3,2,1 };
	vector<int> B = { 3,2,1,4,7 };
	cout << findLength(A, B) << endl;
}
int main()
{
	test();
	return 0;
}