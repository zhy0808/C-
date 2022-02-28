#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s){
	//dp[i][j]��ʾs�е�i������j���ַ����Ƿ�Ϊ���Ĵ�
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	int ret = 0;
	for (int i = s.size() - 1; i >= 0; --i){
		for (int j = i; j < s.size(); ++j){
			//�����i���͵�j����ͬ������Ҫ������ʼ������false
			//�����ͬ������������ǻ��Ĵ���1��i��jָ��ͬһ�ַ���2��i��jָ�������ַ���3��i��j�м仹���ַ������м��ַ����ǻ��Ĵ�
			if (s[i] == s[j]) {
				if (j - i <= 1){
					ret++;
					dp[i][j] = true;
				}
				else if (dp[i + 1][j - 1]) {
					ret++;
					dp[i][j] = true;
				}
			}
		}
	}
	return ret;
}
void test()
{
	cout << countSubstrings("aaaaa") << endl;
}
int main()
{
	test();
	return 0;
}