#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<int> maxinWindows(vector<int>& nums, int n) {
	deque<int> q;
	vector<int> ret;
	for (int i = 0; i < nums.size(); ++i) {
		while (!q.empty() && nums[i] > nums[q.back()]) {
			q.pop_back();
		}
		while (!q.empty() && q.front() <= i - n) {
			q.pop_front();
		}
		q.push_back(i);
		if (i >= n - 1) {
			ret.push_back(nums[q.front()]);
		}
	}
	return ret;
}
void test() {
	vector<int> nums = { 2,3,4,2,6,2,5,1 };
	vector<int> ret;
	ret = maxinWindows(nums, 3);
	for (int e : ret) {
		cout << e << " ";
	}
}
int main() {
	test();
	return 0;
}