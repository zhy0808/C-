#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool istrue(vector<string>& board, int n, int row, int col) {
	for (int i = 0; i < n; ++i) {
		if (board[row][i] == 'Q')
			return false;
	}
	for (int i = 0; i < n; ++i) {
		if (board[i][col] == 'Q')
			return false;
	}
	int i = row, j = col;
	while (i >= 0 && j < n) {
		if (board[i--][j++] == 'Q')
			return false;
	}
	i = row;
	j = col;
	while (i < n && j >= 0) {
		if (board[i++][j--] == 'Q')
			return false;
	}
	i = row;
	j = col;
	while (i >= 0 && j >= 0) {
		if (board[i--][j--] == 'Q')
			return false;
	}
	i = row;
	j = col;
	while (i < n && j < n) {
		if (board[i++][j++] == 'Q') {
			return false;
		}
	}
	return true;
}
void find(vector<vector<string>>& ret, vector<string>& board, int n, int row) {
	if (row == n) {
		ret.push_back(board);
		return;
	}
	for (int col = 0; col < n; ++col) {
		if (istrue(board, n, row, col)) {
			board[row][col] = 'Q';
			find(ret, board, n, row + 1);
			board[row][col] = '.';
		}
	}
}
void nqueen(vector<vector<string>>& ret, int n) {
	vector<string> board(n, string(n, '.'));
	find(ret, board, n, 0);
}
void test() {
	vector<vector<string>> ret;
	nqueen(ret, 4);
	for (int i = 0; i < ret.size(); ++i) {
		for (string e : ret[i]) {
			cout << e << " ";
		}
		cout << endl;
	}
}

int main() {
	test();
	return 0;
}