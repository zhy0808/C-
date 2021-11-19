#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void reverseString(vector<char>& s)
	{
		int lift = 0;
		int right = s.size() - 1;
		while (lift < right)
		{
			char temp = s[lift];
			s[lift] = s[right];
			s[right] = temp;
			lift++;
			right--;
		}
	}
};

void test()
{
	Solution s;
	vector<char> str = { 'h','e','l','l','o' };
	s.reverseString(str);
	for (auto e : str)
	{
		cout << e;
	}
}
int main()
{
	test();
	return 0;
}