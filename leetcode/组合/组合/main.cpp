#include <iostream>
#include <vector>
using namespace std;


void depth(vector<vector<int>>& ret, vector<int>& path, int n, int k, int begin)
{
	if (path.size() == k)      //�����ǰ��¼����Ԫ����������k���򱣴�������������
	{
		ret.push_back(path);
		return;
	}
	for (int i = begin; i <= n - (k - path.size()) + 1; i++)  //��������
	{
		path.push_back(i);               //��¼��ǰ��ֵ
		depth(ret, path, n, k, i + 1);   //�ݹ��жϵ�ǰ��¼����Ԫ������������k
		path.pop_back();                 //������淵�س����ˣ�˵��path���Ѿ���k�����ˣ������Ѿ���¼�����������һ��Ԫ��
	}
}


vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> ret;   //��¼���н��
	vector<int> path;          //��¼��ǰ��������Ԫ��
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