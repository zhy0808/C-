#pragma once
#include <string>
using namespace std;


//template<class K>
//struct TreeNode
//{
//	K _key;
//	TreeNode<K>* _left;
//	TreeNode<K>* _right;
//	TreeNode(const K& k)
//		:_key(k)
//		, _left(nullptr)
//		, _right(nullptr)
//	{
//
//	}
//};
//
//
//template<class K>
//class BSTree
//{
//public:
//	BSTree()
//		:root(nullptr)
//	{
//
//	}
//	bool insert(const K& key)
//	{
//		if (root == nullptr)
//		{
//			root = new TreeNode<K>(key);
//			return true;
//		}
//		else
//		{
//			TreeNode<K>* parent = nullptr;
//			TreeNode<K>* cur = root;
//			while (cur)
//			{
//				if (cur->_key > key)
//				{
//					parent = cur;
//					cur = cur->_left;
//				}
//				else if (cur->_key < key)
//				{
//					parent = cur;
//					cur = cur->_right;
//				}
//				else
//					return false;
//			}
//			TreeNode<K>* newnode = new TreeNode<K>(key);
//			if (parent->_key > key)
//				parent->_left = newnode;
//			else
//				parent->_right = newnode;
//		}
//	}
//	const TreeNode<K>* find(const K& key)
//	{
//		TreeNode<K>* cur = root;
//		while (cur)
//		{
//			if (cur->_key == key)
//			{
//				cout << "find it!" << endl;
//				return cur;
//			}
//			else if (cur->_key > key)
//			{
//				cur = cur->_left;
//			}
//			else
//				cur = cur->_right;
//		}
//		cout << "not find!" << endl;
//		return nullptr;
//	}
//	bool erase(const K& key)
//	{
//		TreeNode<K>* cur = root;
//		TreeNode<K>* parent = nullptr;
//		while (cur)
//		{
//			if (cur->_key > key)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else if (cur->_key < key)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else
//			{
//				//�ҵ���Ӧ�ڵ��ˣ���ʼɾ��
//				//��ǰ�ڵ�����λ�������������
//				//1.��ǰ�ڵ�������Ϊ��
//				if (cur->_left == nullptr)
//				{
//					if (cur == root)
//					{
//						root = root->_right;
//					}
//					else if (cur == parent->_left)
//					{
//						parent->_left = cur->_right;
//					}
//					else if (cur == parent->_right)
//					{
//						parent->_right = cur->_right;
//					}
//					delete cur;
//				}
//				//2.��ǰ�ڵ��������Ϊ��
//				else if (cur->_right == nullptr)
//				{
//					if (cur == root)
//					{
//						root = root->_left;
//					}
//					else if (cur == parent->_left)
//					{
//						parent->_left = cur->_left;
//					}
//					else if (cur == parent->_right)
//					{
//						parent->_right = cur->_left;
//					}
//					delete cur;
//				}
//				//3.��ǰ�ڵ�������������Ϊ��
//				//Ҫ�������������ҽڵ����������������ڵ����滻��ǰ�ڵ�
//				else
//				{
//					TreeNode<K>* tmp = cur->_left;
//					TreeNode<K>* tparent = cur;
//					while (tmp->_right)
//					{
//						tparent = tmp;
//						tmp = tmp->_right;
//					}
//					//�ҵ�����������С�ڵ���
//					cur->_key = tmp->_key;
//					if (tmp == tparent->_left)
//					{
//						tparent->_left = tmp->_left;
//					}
//					else
//					{
//						tparent->_right = tmp->_left;
//					}
//					delete tmp;
//				}
//				return true;
//			}
//		}
//		return false;
//	}
//	void Inorder()
//	{
//		_Inorder(root);
//	}
//private:
//	void _Inorder(TreeNode<K>* cur)
//	{
//		if (cur == nullptr)
//			return;
//		_Inorder(cur->_left);
//		cout << cur->_key << endl;
//		_Inorder(cur->_right);
//	}
//	TreeNode<K>* root;
//};

template<class K,class V>
struct TreeNode
{
	K _key;
	V _val;
	struct TreeNode<K, V>* _left;
	struct TreeNode<K, V>* _right;
	TreeNode(const K& key, const V& val)
		:_key(key)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{

	}
};


template<class K,class V>
class BSTree
{
	typedef TreeNode<K, V> node;
public:
	BSTree()
		:root(nullptr)
	{

	}
	bool insert(const K& key, const V& val)
	{
		if (root == nullptr)
		{
			root = new node(key, val);
		}
		node* cur = root;
		node* parent = nullptr;
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
		node* newnode = new node(key, val);
		if (parent->_key > key)
			parent->_left = newnode;
		else
			parent->_right = newnode;
		return true;
	}
	node* find(const K& key)
	{
		node* cur = root;
		while (cur)
		{
			if (cur->_key > key)
				cur = cur->_left;
			else if (cur->_key < key)
				cur = cur->_right;
			else
			{
				//cout << "�ҵ���" << endl;
				return cur;
			}
		}
		//cout << "û�ҵ�" << endl;
		return nullptr;
	}
	bool erase(const K& key)
	{
		node* cur = root;
		node* parent = nullptr;
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
						parent->_right = cur->_left;
					}
					delete cur;
				}
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
				}
				else
				{
					node* tmp = cur->_left;
					node* tparent = cur;
					while (tmp->_right)
					{
						tparent = tmp;
						tmp = tmp->_right;
					}
					cur->_key = tmp->_key;
					cur->_val = tmp->_val;
					if (tparent->_left == tmp)
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


	void inorder()
	{
		_inorder(root);
	}
private:
	node* root;
	void _inorder(node* cur)
	{
		if (cur == nullptr)
			return;
		_inorder(cur->_left);
		cout << cur->_key << ":" << cur->_val << endl;
		_inorder(cur->_right);
	}
};