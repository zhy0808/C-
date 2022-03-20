#include <iostream>
#include <vector>
using namespace std;

void FindNumsAppearOnce(vector<int>& data, int* num1, int* num2) {
	int ans = 0;
        for (int e : data) {
            ans ^= e;
        }
        int first1 = 0;
        while((ans & (1 << first1)) == 0) {
            first1++;
        }
        
        *num1 = 0;
        *num2 = 0;
        for(int e : data) {
            if((e & (1 << first1)) == 0)
                *num1 ^= e;
            else
                *num2 ^= e;
        }
}
void test() {
	vector<int> nums = { 1,2,3,4,5,67,8,9,1,2,3,4,5,8 };
	int n1 = 0, n2 = 0;
	FindNumsAppearOnce(nums, &n1, &n2);
	cout << n1 << "  " << n2 << endl;
}
void test1() {
    int a = 67;
    int b = 9;
    int c = a ^ b;
    cout << c << endl;
}
int main() {
	test();
	return 0;
}