#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(const int v = 0)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
class Mytree
{
public:
	int rootIndex;
	unordered_map<int, int> map;
	TreeNode* init(int left, int right, vector<int>& inorder, vector<int>& postorder)
	{
		if (left > right)
			return nullptr;
		TreeNode* root = new TreeNode(postorder[rootIndex]);
		int mid = map[postorder[rootIndex]];
		rootIndex--;
		root->right = init(mid + 1, right, inorder, postorder);
		root->left = init(left, mid - 1, inorder, postorder);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		rootIndex = postorder.size() - 1;
		for (int i = 0; i < inorder.size(); i++)
		{
			map[inorder[i]] = i;
		}
		return init(0, inorder.size() - 1, inorder, postorder);
	}
	void Preorder(TreeNode* cur)
	{
		if (cur == nullptr)
			return;
		cout << cur->val << endl;
		Preorder(cur->left);
		Preorder(cur->right);
	}
};
void test()
{
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	Mytree t;
	TreeNode* root = t.buildTree(inorder, postorder);
	t.Preorder(root);
}

int main()
{
	test();
	return 0;
}