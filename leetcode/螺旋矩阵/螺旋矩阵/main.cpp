#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)            //ÿ��ѭ��һ��������
	{
		vector<vector<int>> ret(n, vector<int>(n, 0));
		int startx = 0, starty = 0;                       //Ȧ����λ��
		int count = 1;                                    //Ҫ�������������
		int side = n - 1;                                 //�������ϱߴ����Һ��ұߴ��ϵ��µĳ���
		while (count <= n * n)
		{
			int i = startx;
			int j = starty;
			if (i == n / 2 && j == n / 2)                 //����м�ֻʣһ����λ���Ͳ������������������ˡ�  
			{
				ret[i][j] = count;
				break;
			}
			for (; j < side; j++)                         //���������ϱ�
			{
				ret[i][j] = count++;
			}
			for (; i < side; i++)                         //���������ұ�
			{
				ret[i][j] = count++;
			}
			for (; j > starty; j--)                       //���������±�
			{
				ret[i][j] = count++;
			}
			for (; i > startx; i--)                       //�����������
			{
				ret[i][j] = count++;
			}
			startx++;                                     //��������С�����ε���ʼλ��
			starty++;
			side--;                                       //��������С�����εı߳�
		}


		return ret;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> vv= s.generateMatrix(1);
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] <<" ";
		}
		cout << endl;
	}





	return 0;
}