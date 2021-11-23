#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)            //每次循环一个正方形
	{
		vector<vector<int>> ret(n, vector<int>(n, 0));
		int startx = 0, starty = 0;                       //圈起点的位置
		int count = 1;                                    //要给数组中填的数
		int side = n - 1;                                 //正方形上边从左到右和右边从上到下的长度
		while (count <= n * n)
		{
			int i = startx;
			int j = starty;
			if (i == n / 2 && j == n / 2)                 //如果中间只剩一个空位，就不用往下走填正方形了。  
			{
				ret[i][j] = count;
				break;
			}
			for (; j < side; j++)                         //填正方形上边
			{
				ret[i][j] = count++;
			}
			for (; i < side; i++)                         //填正方形右边
			{
				ret[i][j] = count++;
			}
			for (; j > starty; j--)                       //填正方形下边
			{
				ret[i][j] = count++;
			}
			for (; i > startx; i--)                       //填正方形左边
			{
				ret[i][j] = count++;
			}
			startx++;                                     //更新里面小正方形的起始位置
			starty++;
			side--;                                       //更新里面小正方形的边长
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