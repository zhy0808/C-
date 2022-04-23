#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void Insert(int num) {
        nums.push_back(num);
    }

    double GetMedian() {
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 1) {
            return nums[nums.size() / 2];
        }
        else {
            return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        }
    }
    vector<double> nums;
};

void test() {
    Solution s;
    for (int i = 1; i < 10; ++i) {
        s.Insert(i);
        cout << s.GetMedian() << endl;
    }

}
int main() {
	test();
	return 0;
}