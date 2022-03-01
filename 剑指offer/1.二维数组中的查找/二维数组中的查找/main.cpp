#include <iostream>
#include <vector>
using namespace std;

bool find(vector<vector<int>>& nums, int tar) {
	int i = 0;
	int j = nums[0].size() - 1;
	while (i < nums.size() && j >= 0) {
		if (nums[i][j] < tar) {
			++i;
		}
		else if (nums[i][j] > tar) {
			--j;
		}
		else {
			return true;
		}
	}
	return false;
}
void test(){
	vector<vector<int>> nums = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
	cout << find(nums, 7) << endl;
}
int main(){
	test();
	return 0;
}