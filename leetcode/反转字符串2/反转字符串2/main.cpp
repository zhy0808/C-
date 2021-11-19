#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseString(string& s, int k)
	{
		int lift = 0;
		int right = lift + k - 1;
		while (lift < s.size()-1)
		{
			if (right > s.size() - 1)    //��������䲻��k��Ԫ�أ�����ʣ�����е�Ԫ��
			{
				reverse(s.begin() + lift, s.end());
				break;
			}
			reverse(s.begin() + lift, s.begin() + right + 1);  //����k��Ԫ�أ�reverse����������ҿ����䣬�����ұ߽�Ҫ+1
			lift += 2 * k;   //���µ���һ��2k����
			right += 2 * k;
		}
	}
};
void test()
{
	Solution s;
	string str("abcdefg");
	s.reverseString(str, 6);
	cout << str << endl;
}
int main()
{
	test();
	return 0;
}