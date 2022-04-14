#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool func(vector<vector<char>>& s, string str, int begin, int i, int j) {
	if (i < 0 || i == s.size() || j < 0 || j == s[0].size() || s[i][j] != str[begin]) {
		return false;
	}
	if (begin == str.size() - 1)
		return true;
	s[i][j] = ' ';
	begin++;
	bool ret = func(s, str, begin, i + 1, j) || func(s, str, begin, i - 1, j) || func(s, str, begin, i, j + 1) || func(s, str, begin, i, j - 1);
	//bool ret = func(s, str, begin + 1, i + 1, j) || func(s, str, begin + 1, i - 1, j) || func(s, str, begin + 1, i, j + 1) || func(s, str, begin + 1, i, j - 1);

	begin--;
	s[i][j] = str[begin];
	return ret;
}
bool hasPath(char* matrix, int rows, int cols, string str) {
	int k = 0;
	vector<vector<int>> flag(rows, vector<int>(cols, 0));
	vector<vector<char>> s(rows, vector<char>(cols));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			s[i][j] = matrix[k++];
		}
	}
	for (int i = 0; i < s.size(); ++i) {
		for (int j = 0; j < s[0].size(); ++j) {
			if (func(s, str, 0, i, j))
				return true;
		}
	}
	return false;

}
void test() {
	char matrix[13] = {'A', 'B', 'C', 'E', 'S', 'F', 'C', 'S', 'A', 'D', 'E', 'E'};
	cout << hasPath(matrix, 3, 4, "ABCCED") << endl;
}
int main() {
	test();
	return 0;
}