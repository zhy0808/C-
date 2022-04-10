#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum(int index1, int index2, vector<int>& nums1, vector<int>& nums2) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < index1; ++i) {
        a = a * 10 + nums1[i];
    }
    for (int i = index1; i < nums1.size(); ++i) {
        b = b * 10 + nums1[i];
    }
    for (int i = 0; i <= index2; ++i) {
        c = c * 10 + nums2[i];
    }
    for (int i = index2 + 1; i < nums2.size(); ++i) {
        d = d * 10 + nums2[i];
    }
    if (a == 0)
        a = 1;
    if (d == 0)
        d = 1;
    return a * (b + c) * d;
}
string minimizeResult(string expression) {
    vector<int> nums1;
    vector<int> nums2;
    int flag = 0;
    for (char c : expression) {
        if (c == '+') {
            flag = 1;
            continue;
        }
        if (flag == 0) {
            nums1.push_back(c - '0');
        }
        else {
            nums2.push_back(c - '0');
        }
    }
    //记录算式最小时括号位置
    int x = 0, y = 0;
    int min = INT_MAX;
    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = nums2.size() - 1; j >= 0; --j) {
            //计算括号插入在i，倒数j位置时，式子的值
            int ans = sum(i, j, nums1, nums2);
            if (ans < min) {
                min = ans;
                x = i;
                y = nums2.size() - j;
            }
        }
    }
    //在对应位置插入括号
    expression.insert(expression.begin() + x, '(');
    expression.insert(expression.end() - y + 1, ')');
    return expression;

}

int main() {
    string ret;
    ret = minimizeResult("999+999");
    cout << ret << endl;
}