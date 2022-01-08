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
				//   >=   该题允许出现重复值
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
			
			//   >=   该题允许出现重复值
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

//搜索二叉树中序遍历是有序序列，对该树进行中序遍历，统计相同值出现的次数curmax与最大出现次数相比
vector<int> find(TreeNode<int>* root)
{
	vector<int> ret;
	if (root == nullptr)
		return ret;
	stack<TreeNode<int>*> s;     //用栈模拟递归进行中序遍历
	TreeNode<int>* cur = root;
	TreeNode<int>* pre = nullptr; //保存前一个节点
	int curmax = 1;  //当前节点值出现的次数
	int max = 0;     //整个树中出现最多的值的次数
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
				//比较当前节点与前一个节点的值
				//如果相同，将该值出现的次数加一
				//如果不同，统计当前节点值出现的次数，将curmax置为1
				if (pre->_key == cur->_key)
					curmax++;
				else
					curmax = 1;
			}
			//如果当前节点出现的次数比前面统计的出现最多的次数还大，将数组清空，把当前节点的值push进去
			//同时更新出现最多的次数
			if (curmax > max)
			{
				ret.clear();
				ret.push_back(cur->_key);
				max = curmax;
			}
			//如果当前节点出现的次数和最大值相同，push当前节点的值
			else if (curmax == max)
			{
				ret.push_back(cur->_key);
			}
			//更新前一个节点
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