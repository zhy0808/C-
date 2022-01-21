#include <iostream>
#include <vector>
using namespace std;
//dp数组下标表示节点个数，内容表示有当前这些节点一共可以组成多少二叉搜索树
int numTrees(int n)
{
	vector<int> dp(n + 1);
	dp[0] = 1;
	//算出每i个节点可以组成多少个二叉搜索树
	for (int i = 1; i <= n; ++i)
	{
		//当前二叉搜索树可以分为左子树和右子树，左子树和右子树所含有的节点组成二叉搜索树在dp数组前面已经计算出来了
		//j从1开始，左子树含有j-1个节点，则右子树含有i-j个节点，将两部分节点可以组成的二叉搜索树的个数相乘就是当前节点可以组成二叉搜索树的总个数

		for (int j = 1; j <= i; ++j)
		{
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}

void test()
{
	cout << numTrees(3) << endl;
}
int main()
{
	test();
	return 0;
}