#include <iostream>
#include <vector>
using namespace std;
int wiggleMaxLength(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();
	int ret = 1;
	int prev = 0;
	int cur = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		cur = nums[i + 1] - nums[i];
		//�����ǰû��ҡ�ڣ�ǰһ�εĲ�ֵ�������䣬�м�ͬ���ŵĲ�ֵȫ������
		if ((cur > 0 && prev <= 0) || (cur < 0 && prev >= 0)) {
			ret++;
			prev = cur;
		}
	}
	return ret;
}
void test() {
	vector<int> nums = { 1,17,5,10,13,15,10,5,16,8 };
	cout << wiggleMaxLength(nums) << endl;
}
int main() {
	test();
	return 0;
}