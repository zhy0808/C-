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


//��֤������������������������ǰһ���ڵ�ȵ�ǰ�ڵ��ֵ�����ȣ���������������
TreeNode<int>* pre = nullptr;  //��¼ǰһ���ڵ�
bool IsBSTree(TreeNode<int>* cur)
{
	if (cur == nullptr)
		return true;
	bool left = IsBSTree(cur->_left);  //����������
	if (pre != nullptr && pre->_key >= cur->_key)//��ǰ�ڵ��ֵ��ǰһ���ڵ��ֵС����ȣ�˵����������������
		return false;
	//һ���������������ǰһ���ڵ㣺
	//��ǰ�ڵ��ǰһ���ڵ�Ϊ�գ�˵����ǰ�ڵ�������ڵ�
	//��ǰ�ڵ��ֵ��ǰһ���ڵ��ֵ��
	pre = cur;
	bool right = IsBSTree(cur->_right);
	return left && right;
}
//���������������
bool IsBSTree1(TreeNode<int>* root)
{
	if (root == nullptr)
		return true;
	TreeNode<int>* cur = root;
	TreeNode<int>* pre = nullptr;
	stack<TreeNode<int>*> s;
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
			if (pre != nullptr && pre->_key >= cur->_key)
				return false;
			pre = cur;
			cur = cur->_right;
		}
	}
	return true;
}
void test()
{
	BSTree<int> bst;
	bst.insert(6);
	bst.insert(9);
	bst.insert(2);
	bst.insert(5);
	bst.insert(1);
	bst.insert(7);
	bst.insert(3);
	bst.insert(8);
	//bst.Inorder();
	cout << IsBSTree(bst.getRoot()) << endl;
	cout << IsBSTree1(bst.getRoot()) << endl;
}

int main()
{
	test();
	return 0;
}