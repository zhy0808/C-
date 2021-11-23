#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ret;
        int up = 0;                      //记录二维数组上下左右四个边界
        int down = m.size() - 1;
        int lift = 0;
        int right = m[0].size() - 1;
        while (1)
        {
            for (int i = lift; i <= right; i++)      //把上边界上的数据依次存入ret
            {
                ret.push_back(m[up][i]);
            }
            if (++up > down)                         //更新上边界，并判断是否遍历完整个二维数组
                break;
            for (int i = up; i <= down; i++)         //把右边界上的数据依次存入ret
            {
                ret.push_back(m[i][right]);
            }
            if (--right < lift)                      //更新右边界，并判断是否遍历完整个二维数组
                break;
            for (int i = right; i >= lift; i--)      //把下边界上的数据依次存入ret
            {
                ret.push_back(m[down][i]);
            }
            if (--down < up)                         //更新下边界，并判断是否遍历完整个二维数组
                break;
            for (int i = down; i >= up; i--)         //把左边界上的数据一次存入ret
            {
                ret.push_back(m[i][lift]);
            }
            if (++lift > right)                      //更新左边界，并判断是否遍历完整个二维数组
                break;
        }
        return ret;
    }
};



int main()
{
    Solution s;
    vector<vector<int>> vv = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    vector<int> v;
    v = s.spiralOrder(vv);
    vector<int>::iterator it= v.begin();
    while (it != v.end())
    {
        cout << *it << endl;
        it++;
    }
	return 0;
}