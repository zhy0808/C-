#include <iostream>
#include <vector>
using namespace std;
int minNumberInRotateArray(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; ++i) {
		if (nums[i] > nums[i + 1]) {
			return nums[i + 1];
		}
	}
	return nums[0];
}

void test() {
	vector<int> nums = { 3,4,5,1,2 };
	cout << minNumberInRotateArray(nums) << endl;
}
int main()
{
	test();
	return 0;
}