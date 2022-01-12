#include <iostream>
#include <stack>
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
//迭代，二叉搜索树中序遍历是从小到大的序列，用每个节点减去前一个节点的值，跟最小值比较
int getMinimumDifference(TreeNode<int>* root)
{
	if (root == nullptr)
		return 0;
	TreeNode<int>* cur = root;
	TreeNode<int>* pre = nullptr;
	stack<TreeNode<int>*> s;
	int ret = 1000000;
	while (cur != nullptr || !s.empty())
	{
		if (cur != nullptr)
		{
			s.push(cur);
			cur = cur->_left;
		}
		else
		{
			cur = s.top();
			s.pop();
			if (pre != nullptr)
			{
				int res = cur->_key - pre->_key;
				if (res < ret)
					ret = res;
			}
			pre = cur;
			cur = cur->_right;
		}
	}
	return ret;
}
//递归
TreeNode<int>* pre1 = nullptr;
int ret1 = 1000000;
int getMinimumDifference1(TreeNode<int>* root)
{
	if (root == nullptr)
		return 0;
	getMinimumDifference1(root->_left);
	if (pre1 != nullptr)
	{
		int res = root->_key - pre1->_key;
		if (res < ret1)
			ret1 = res;
	}
	pre1 = root;
	getMinimumDifference1(root->_right);

	return ret1;
	
}
void test()
{
	BSTree<int> t;
	t.insert(4);
	t.insert(2);
	t.insert(6);
	t.insert(1);
	t.insert(3);
	cout << getMinimumDifference(t.getRoot()) << endl;
	cout << getMinimumDifference1(t.getRoot()) << endl;


}
int main()
{
	test();
	return 0;
}