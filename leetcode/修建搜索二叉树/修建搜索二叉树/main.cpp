#include <iostream>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
class BSTree
{
public:
	BSTree()
		:root(nullptr)
	{

	}
	bool insert(int v)
	{
		if (root == nullptr)
		{
			root = new TreeNode(v);
			return true;
		}
		TreeNode* cur = root;
		TreeNode* parent = nullptr;
		while (cur)
		{
			if (cur->val > v)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < v)
			{
				parent = cur;
				cur = cur->right;
			}
			else
				return false;
		}
		TreeNode* node = new TreeNode(v);
		if (parent->val > v)
			parent->left = node;
		else
			parent->right = node;
		return true;
	}
	TreeNode* getroot()
	{
		return root;
	}
	void inorder()
	{
		_inorder(root);
	}
private:
	void _inorder(TreeNode* cur)
	{
		if (cur == nullptr)
			return;
		_inorder(cur->left);
		cout << cur->val << endl;
		_inorder(cur->right);
	}
	TreeNode* root;
};

TreeNode* trimBST(TreeNode* root, int l, int h)
{
	if (root == nullptr)
		return nullptr;
	//如果当前根节点的值比范围小，则抛弃左子树，在右子树中继续修剪
	if (root->val < l)
		return trimBST(root->right, l, h);
	//如果当前根节点的值比范围大，则抛弃右子树，在左子树中继续修剪
	if (root->val > h)
		return trimBST(root->left, l, h);
	//如果当前根节点的值在范围中，分别修建其左右子树
	root->left = trimBST(root->left, l, h);
	root->right = trimBST(root->right, l, h);
	return root;
}
void test()
{
	BSTree t;
	t.insert(3);
	t.insert(0);
	t.insert(4);
	t.insert(2);
	t.insert(1);
	trimBST(t.getroot(), 1, 3);
	t.inorder();

}
int main()
{
	test();
	return 0;
}

