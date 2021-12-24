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
	//�����ǰ���ڵ��ֵ�ȷ�ΧС�������������������������м����޼�
	if (root->val < l)
		return trimBST(root->right, l, h);
	//�����ǰ���ڵ��ֵ�ȷ�Χ�������������������������м����޼�
	if (root->val > h)
		return trimBST(root->left, l, h);
	//�����ǰ���ڵ��ֵ�ڷ�Χ�У��ֱ��޽�����������
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

