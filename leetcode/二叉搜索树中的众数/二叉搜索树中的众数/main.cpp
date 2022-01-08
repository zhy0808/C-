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
				//   >=   ������������ظ�ֵ
				if (cur->_key >= key)
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
			
			//   >=   ������������ظ�ֵ
			if (parent->_key >= key)
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

//��������������������������У��Ը����������������ͳ����ֵͬ���ֵĴ���curmax�������ִ������
vector<int> find(TreeNode<int>* root)
{
	vector<int> ret;
	if (root == nullptr)
		return ret;
	stack<TreeNode<int>*> s;     //��ջģ��ݹ�����������
	TreeNode<int>* cur = root;
	TreeNode<int>* pre = nullptr; //����ǰһ���ڵ�
	int curmax = 1;  //��ǰ�ڵ�ֵ���ֵĴ���
	int max = 0;     //�������г�������ֵ�Ĵ���
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
				//�Ƚϵ�ǰ�ڵ���ǰһ���ڵ��ֵ
				//�����ͬ������ֵ���ֵĴ�����һ
				//�����ͬ��ͳ�Ƶ�ǰ�ڵ�ֵ���ֵĴ�������curmax��Ϊ1
				if (pre->_key == cur->_key)
					curmax++;
				else
					curmax = 1;
			}
			//�����ǰ�ڵ���ֵĴ�����ǰ��ͳ�Ƶĳ������Ĵ������󣬽�������գ��ѵ�ǰ�ڵ��ֵpush��ȥ
			//ͬʱ���³������Ĵ���
			if (curmax > max)
			{
				ret.clear();
				ret.push_back(cur->_key);
				max = curmax;
			}
			//�����ǰ�ڵ���ֵĴ��������ֵ��ͬ��push��ǰ�ڵ��ֵ
			else if (curmax == max)
			{
				ret.push_back(cur->_key);
			}
			//����ǰһ���ڵ�
			pre = cur;
			cur = cur->_right;
		}
	}
	return ret;
}
int treemax = 0;
int curmax = 1;
TreeNode<int>* pre = nullptr;
void f(TreeNode<int>* cur, vector<int>& ret)
{
	if (cur == nullptr)
		return;
	f(cur->_left, ret);
	if (pre != nullptr)
	{
		if (pre->_key == cur->_key)
			curmax++;
		else
			curmax = 1;
	}
	if (curmax > treemax)
	{
		ret.clear();
		ret.push_back(cur->_key);
		treemax = curmax;
	}
	else if (curmax == treemax)
	{
		ret.push_back(cur->_key);
	}
	pre = cur;
	f(cur->_right, ret);

}
vector<int> find1(TreeNode<int>* root)
{
	vector<int> ret;
	f(root, ret);
	return ret;
}
void test()
{
	BSTree<int> t;
	t.insert(1);
	t.insert(2);
	t.insert(2);
	t.insert(2);
	t.insert(3);
	t.insert(3);
	t.insert(3);
	t.insert(4);
	t.insert(4);
	t.insert(4);
	t.insert(5);
	t.insert(5);
	t.insert(5);
	t.insert(5);
	t.insert(5);
	t.insert(5);


	//t.Inorder();
	vector<int> ret;
	ret = find(t.getRoot());
	for (auto e : ret)
	{
		cout << e << endl;
	}
	vector<int> ret1;
	ret1 = find1(t.getRoot());
	for (auto e : ret1)
	{
		cout << e << endl;
	}
}
int main()
{
	test();
	return 0;
}