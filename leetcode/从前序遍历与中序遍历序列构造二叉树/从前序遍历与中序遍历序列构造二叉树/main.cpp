#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int v = 0)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
int root_index;
unordered_map<int, int> map;
TreeNode* initTree(int left, int right, vector<int>& preorder, vector<int>& inorder)
{
	if (left > right)
		return nullptr;
	TreeNode* root = new TreeNode(preorder[root_index]);
	int mid = map[root->val];
	root_index++;
	root->left = initTree(left, mid - 1, preorder, inorder);
	root->right = initTree(mid + 1, right, preorder, inorder);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	root_index = 0;
	for (int i = 0; i < inorder.size(); i++)
	{
		map[inorder[i]] = i;
	}
	return initTree(0, inorder.size() - 1, preorder, inorder);
}


void Preorder(TreeNode* cur)
{
	if (cur == nullptr)
		return;
	cout << cur->val << endl;
	Preorder(cur->left);
	Preorder(cur->right);
}
void test()
{
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode* root = buildTree(preorder, inorder);
	Preorder(root);

}

int main()
{
	test();
	return 0;
}