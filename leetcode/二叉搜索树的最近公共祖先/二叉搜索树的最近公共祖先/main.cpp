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
				//�ҵ���Ӧ�ڵ��ˣ���ʼɾ��
				//��ǰ�ڵ�����λ�������������
				//1.��ǰ�ڵ�������Ϊ��
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
				//2.��ǰ�ڵ��������Ϊ��
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
				//3.��ǰ�ڵ�������������Ϊ��
				//Ҫ�������������ҽڵ����������������ڵ����滻��ǰ�ڵ�
				else
				{
					TreeNode<K>* tmp = cur->_left;
					TreeNode<K>* tparent = cur;
					while (tmp->_right)
					{
						tparent = tmp;
						tmp = tmp->_right;
					}
					//�ҵ�����������С�ڵ���
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

//��������������ǰ�ڵ��ֵλ��pqֵ���м�λ�ã�˵����ǰ�ڵ���������������
TreeNode<int>* find(TreeNode<int>* cur, int p, int q)
{
	if (cur == nullptr)
		return nullptr;
	//�����ǰ�ڵ�ֵ��pq����˵��pq�ڵ�ǰ�ڵ����
	if (cur->_key > p && cur->_key > q)
	{
		TreeNode<int>* left = find(cur->_left, p, q);
		if (left != nullptr)
			return left;
	}
	//�����ǰ�ڵ�ֵ��pq��С��˵��pq�ڵ�ǰ�ڵ��ұ�
	if (cur->_key < p && cur->_key < q)
	{
		TreeNode<int>* right = find(cur->_right, p, q);
		if (right != nullptr)
			return right;
	}
	//�����ǰ�ڵ�ֵλ��pq�м䣬ֱ�ӷ���
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