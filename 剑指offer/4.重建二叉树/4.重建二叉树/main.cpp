#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v = 0)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{

	}
};

TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& in) {

}
void test() {
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> in = { 4,7,2,1,5,3,8,6 };
	TreeNode* root;
	root = reConstructBinaryTree(pre, in);
}
int main() {
	test();
	return 0;
}