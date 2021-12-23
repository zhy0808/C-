#include <iostream>
#include <vector>
using namespace std;


void depth(vector<vector<int>>& ret, vector<int>& path, int n, int k, int begin)
{
	if (path.size() == k)      //如果当前记录到的元素数量等于k，则保存这组数并返回
	{
		ret.push_back(path);
		return;
	}
	for (int i = begin; i <= n - (k - path.size()) + 1; i++)  //遍历数组
	{
		path.push_back(i);               //记录当前的值
		depth(ret, path, n, k, i + 1);   //递归判断当前记录到的元素数量够不够k
		path.pop_back();                 //如果上面返回出来了，说明path中已经够k个数了，并且已经记录过，弹出最后一个元素
	}
}


vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ret;   //记录所有结果
	vector<int> path;          //记录当前遍历到的元素
	depth(ret, path, n, k, 1);
	return ret;
}

void test()
{
	vector<vector<int>> ret;
	ret = combine(4, 2);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	test();
	return 0;
}