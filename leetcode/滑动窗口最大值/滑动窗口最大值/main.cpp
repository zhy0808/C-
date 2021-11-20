#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		deque<int> dq;           //˫�˶���
		vector<int> ret;
		for (int i = 0; i < k; i++)  //����һ�������е����ݷ���˫�˶��У�����֤��Щ���Ӵ�С����
		{
			while (!dq.empty() && nums[i] > dq.back()) //����½����е���������ǰһ����������ǰһ��������
			{
				dq.pop_back();
			}
			dq.push_back(nums[i]);  //ǰ�涼�Ǳ��½��ӵ������ˣ�����������
		}
		ret.push_back(dq.front());  //��һ�����ڵ����ֵ���ǵ�ǰ��ͷ
		for (int i = k; i < nums.size(); i++)  //������󻬶�
		{
			if (dq.front() == nums[i - k])     //�Ѳ�����������ڵ������Ƴ�����
				dq.pop_front();
			while (!dq.empty() && nums[i] > dq.back())  //����½��ӵ����ȶ�����֮ǰ�����ݴ�������ǰһ��������
			{
				dq.pop_back();
			}
			dq.push_back(nums[i]);       //ǰ��������ȸ������ˣ�����������
			ret.push_back(dq.front());   //��ǰ�������ֵ���Ƕ�ͷ
		}
		return ret;
	}
};
void test()
{
	Solution s;
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> res;
	res = s.maxSlidingWindow(nums, 3);
	for (auto e : res)
	{
		cout << e << endl;
	}
}
int main()
{
	test();
	return 0;
}