#include <iostream>
#include <stack>
#include <vector>
using namespace std;


template<class K>
struct TreeNode
{
	K _key;
	TreeNode<K>* _left;
	TreeNode<K>* _right;
	TreeNode(const K& k)
		:_key(k)
		, _left(nullptr)
		, _right(nullptr)
	{

	}
};


template<class K>
class BSTree
{
public:
	BSTree()
		:root(nullptr)
	{

	}
	bool insert(const K& key)
	{
		if (root == nullptr)
		{
			root = new TreeNode<K>(key);
			return true;
		}
		else
		{
			TreeNode<K>* parent = nullptr;
			TreeNode<K>* cur = root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					return false;
			}
			TreeNode<K>* newnode = new TreeNode<K>(key);

			if (parent->_key > key)
				parent->_left = newnode;
			else
				parent->_right = newnode;
		}
	}
	const TreeNode<K>* find(const K& key)
	{
		TreeNode<K>* cur = root;
		while (cur)
		{
			if (cur->_key == key)
			{
				cout << "find it!" << endl;
				return cur;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
				cur = cur->_right;
		}
		cout << "not find!" << endl;
		return nullptr;
	}
	bool erase(const K& key)
	{
		TreeNode<K>* cur = root;
		TreeNode<K>* parent = nullptr;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//找到对应节点了，开始删除
				//当前节点所处位置有三种情况：
				//1.当前节点左子树为空
				if (cur->_left == nullptr)
				{
					if (cur == root)
					{
						root = root->_right;
					}
					else if (cur == parent->_left)
					{
						parent->_left = cur->_right;
					}
					else if (cur == parent->_right)
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}
				//2.当前节点的右子树为空
				else if (cur->_right == nullptr)
				{
					if (cur == root)
					{
						root = root->_left;
					}
					else if (cur == parent->_left)
					{
						parent->_left = cur->_left;
					}
					else if (cur == parent->_right)
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}
				//3.当前节点左右子树都不为空
				//要找左子树的最右节点或者右子树的最左节点来替换当前节点
				else
				{
					TreeNode<K>* tmp = cur->_left;
					TreeNode<K>* tparent = cur;
					while (tmp->_right)
					{
						tparent = tmp;
						tmp = tmp->_right;
					}
					//找到左子树的最小节点了
					cur->_key = tmp->_key;
					if (tmp == tparent->_left)
					{
						tparent->_left = tmp->_left;
					}
					else
					{
						tparent->_right = tmp->_left;
					}
					delete tmp;
				}
				return true;
			}
		}
		return false;
	}
	void Inorder()
	{
		_Inorder(root);
	}
	TreeNode<K>* getRoot()
	{
		return root;
	}

private:
	void _Inorder(TreeNode<K>* cur)
	{
		if (cur == nullptr)
			return;
		_Inorder(cur->_left);
		cout << cur->_key << endl;
		_Inorder(cur->_right);
	}
	TreeNode<K>* root;
};

//中序遍历，如果当前节点的值位于pq值的中间位置，说明当前节点就是最近公共祖先
TreeNode<int>* find(TreeNode<int>* cur, int p, int q)
{
	if (cur == nullptr)
		return nullptr;
	//如果当前节点值比pq都大，说明pq在当前节点左边
	if (cur->_key > p && cur->_key > q)
	{
		TreeNode<int>* left = find(cur->_left, p, q);
		if (left != nullptr)
			return left;
	}
	//如果当前节点值比pq都小，说明pq在当前节点右边
	if (cur->_key < p && cur->_key < q)
	{
		TreeNode<int>* right = find(cur->_right, p, q);
		if (right != nullptr)
			return right;
	}
	//如果当前节点值位于pq中间，直接返回
	return cur;
}
TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root,int p,int q)
{
	return find(root, p, q);
}
TreeNode<int>* lowestCommonAncestor1(TreeNode<int>* root, int p, int q)
{
	TreeNode<int>* cur = root;
	while (cur)
	{
		if (cur->_key > p && cur->_key > q)
			cur = cur->_left;
		else if (cur->_key < p && cur->_key < q)
			cur = cur->_right;
		else
			return cur;
	}
	return nullptr;
}
void test()
{
	BSTree<int> t;
	t.insert(6);
	t.insert(2);
	t.insert(8);
	t.insert(0);
	t.insert(4);
	t.insert(7);
	t.insert(9);
	t.insert(3);
	t.insert(5);
	TreeNode<int>* ret;
	ret = lowestCommonAncestor(t.getRoot(), 2, 8);
	cout << ret->_key << endl;
	ret = lowestCommonAncestor1(t.getRoot(), 2, 8);
	cout << ret->_key << endl;
}
int main()
{
	test();
	return 0;
}