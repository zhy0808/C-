#include <iostream>
#include <vector>
using namespace std;

bool isNumber(string s) {
    bool e = false, sign = false, point = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'e' || s[i] == 'E') {
            if (e == true)
                return false;
            if (i == s.size() - 1)
                return false;
            if (i == 0)
                return false;
            e = true;
        }
        else if (s[i] == '+' || s[i] == '-') {
            if (sign == true && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
            if (sign == false && i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
            sign = true;
        }
        else if (s[i] == '.') {
            if (point == true)
                return false;
            if (e == true)
                return false;
            if (i == 0 && s.size() == 1)
                return false;
            point = true;
        }
        else if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}
void test() {
    cout << isNumber("1") << endl;
}
int main() {
	test();
	return 0;
}