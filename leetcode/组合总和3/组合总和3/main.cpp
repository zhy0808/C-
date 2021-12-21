#include <iostream>
#include <vector>
using namespace std;


void find(int k, int n, vector<vector<int>>& ret, vector<int>& path, int begin,int sum)
{
	if (sum > n)
		return;
	if (path.size() == k && sum == n)
	{
		ret.push_back(path);
		return;
	}
	for (int i = begin; i <= 10-(k-path.size()); i++)
	{
		path.push_back(i);
		find(k, n, ret, path, i + 1, sum + i);
		path.pop_back();
	}

}
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> ret;
	vector<int> path;
	find(k, n, ret, path, 1,0);
	return ret;
}
void test()
{
	vector<vector<int>> ret;
	ret = combinationSum3(3, 9);
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