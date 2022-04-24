#include <iostream>
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
void inorder(vector<int>& tree, TreeNode<int>* cur) {
	if (cur == nullptr) {
		return;
	}
	inorder(tree, cur->_left);
	tree.push_back(cur->_key);
	inorder(tree, cur->_right);
}
int kthLargest(TreeNode<int>* root, int k) {
	vector<int> tree;
	inorder(tree, root);
	return tree[tree.size() - k];
}
void test() {
	BSTree<int> bt;
	bt.insert(3);
	bt.insert(1);
	bt.insert(4);
	bt.insert(2);
	cout << kthLargest(bt.getRoot(), 1) << endl;
}
int main() {
	test();
	return 0;
}