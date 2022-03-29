#include <iostream>
#include <vector>
using namespace std;

int Sum(int i, int j) {
	int ret = 0;
	while (i) {
		ret += i % 10;
		i /= 10;
	}
	while (j) {
		ret += j % 10;
		j /= 10;
	}
	return ret;
}

void dfs(vector<vector<int>>& nums, int i, int j, int thr, int& ret) {
	if (i < 0 || j < 0 || i >= nums.size() || j >= nums[0].size() ||nums[i][j] == 1 || Sum(i, j) > thr)
		return;
	ret++;
	nums[i][j] = 1;
	dfs(nums, i + 1, j, thr, ret);
	dfs(nums, i - 1, j, thr, ret);
	dfs(nums, i, j - 1, thr, ret);
	dfs(nums, i, j + 1, thr, ret);
}
int movingCount(int thr, int r, int c) {
	int ret = 0;
	vector<vector<int>> nums(r, vector<int>(c, 0));
	dfs(nums, 0, 0, thr, ret);
	return ret;
}
void test() {
	cout << movingCount(5, 10, 10) << endl;
}
int main() {
	test();
	return 0;
}