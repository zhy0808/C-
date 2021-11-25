#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		vector<int> v(26, 0);
		for (auto e : ransomNote)
		{
			v[e - 'a']++;
		}
		for (auto e : magazine)
		{
			v[e - 'a']--;
		}
		for (auto e : v)
		{
			if (e > 0)
			{
				return false;
			}
		}
		return true;
	}
};

void test()
{
	Solution s;
	cout << s.canConstruct("asd", "aassdd") << endl;
}

int main()
{
	test();
	return 0;
}