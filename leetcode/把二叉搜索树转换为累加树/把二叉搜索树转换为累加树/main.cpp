#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode
{
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
			if (cur->val < v)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->val > v)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return false;
			}
		}
		TreeNode* node = new TreeNode(v);
		if (parent->val > v)
		{
			parent->left = node;
		}
		else
		{
			parent->right = node;
		}
		return true;
	}
	void inorder()
	{
		_inorder(root);
	}
	TreeNode* getroot()
	{
		return root;
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
int pre = 0;
void sum(TreeNode* cur)
{
	if (cur == nullptr)
		return;
	//�ȱ���������
	sum(cur->right);
	//�����ҽڵ㿪ʼ�ۼ�
	cur->val += pre;
	//ÿ���ۼ��꣬����ǰ�ڵ��ֵ������pre�У��Ա��´��ۼ�ʹ��
	pre = cur->val;
	sum(cur->left);
}
//�ݹ�
TreeNode* convertBST(TreeNode* root)
{
	sum(root);
	return root;
}
//����
TreeNode* convertBST1(TreeNode* root)
{
	TreeNode* cur = root;
	stack<TreeNode*> s;
	int pre = 0;
	while (cur != nullptr || !s.empty())
	{
		if (cur != nullptr)
		{
			s.push(cur);
			cur = cur->right;
		}
		else
		{
			cur = s.top();
			s.pop();
			cur->val += pre;
			pre = cur->val;
			cur = cur->left;
		}
	}
	return root;
}
void test()
{
	BSTree t;
	t.insert(4);
	t.insert(1);
	t.insert(6);
	t.insert(0);
	t.insert(2);
	t.insert(5);
	t.insert(7);
	t.insert(3);
	t.insert(8);
	//t.inorder();
	//convertBST(t.getroot());
	//t.inorder();
	convertBST1(t.getroot());
	t.inorder();
}

int main()
{
	test();
	return 0;
}