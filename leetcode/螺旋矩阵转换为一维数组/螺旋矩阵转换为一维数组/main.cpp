#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ret;
        int up = 0;                      //��¼��ά�������������ĸ��߽�
        int down = m.size() - 1;
        int lift = 0;
        int right = m[0].size() - 1;
        while (1)
        {
            for (int i = lift; i <= right; i++)      //���ϱ߽��ϵ��������δ���ret
            {
                ret.push_back(m[up][i]);
            }
            if (++up > down)                         //�����ϱ߽磬���ж��Ƿ������������ά����
                break;
            for (int i = up; i <= down; i++)         //���ұ߽��ϵ��������δ���ret
            {
                ret.push_back(m[i][right]);
            }
            if (--right < lift)                      //�����ұ߽磬���ж��Ƿ������������ά����
                break;
            for (int i = right; i >= lift; i--)      //���±߽��ϵ��������δ���ret
            {
                ret.push_back(m[down][i]);
            }
            if (--down < up)                         //�����±߽磬���ж��Ƿ������������ά����
                break;
            for (int i = down; i >= up; i--)         //����߽��ϵ�����һ�δ���ret
            {
                ret.push_back(m[i][lift]);
            }
            if (++lift > right)                      //������߽磬���ж��Ƿ������������ά����
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