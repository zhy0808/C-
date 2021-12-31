#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
		:val(0)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
class Mytree
{
public:
	Mytree()
		:root(nullptr)
	{

	}
	TreeNode* init(vector<int>& nums, int n = 0)
	{
		if (n >= nums.size())
			return nullptr;
		TreeNode* tmp = new TreeNode();
		tmp->val = nums[n];
		tmp->left = init(nums, n * 2 + 1);
		tmp->right = init(nums, n * 2 + 2);
		root = tmp;
		return root;
	}

	//前序遍历，先将根节点存入路径里，在遍历左右节点，如果左右节点为空，就把当前路径记录下来
	void func(vector<string>& ret, TreeNode* node, vector<int>& path)
	{
		path.push_back(node->val);
		if (node->left)
		{
			func(ret, node->left, path);         
			path.pop_back();                    //返回到这里时，说明左子树已经遍历完了，要清除已经遍历过的路径
		}
		if (node->right)
		{
			func(ret, node->right, path);
			path.pop_back();
		}
		if (node->left == nullptr && node->right == nullptr)  //如果当前节点是叶子节点，保存当前路径
		{
			string s;
			int i;
			for (i = 0; i < path.size() - 1; i++)
			{
				s += to_string(path[i]);
				s += "->";
			}
			s += to_string(path[i]);
			ret.push_back(s);
		}
	}
	vector<string> binaryTreePaths()
	{
		vector<string> ret;    //记录所有结果
		vector<int> path;      //记录从根节点到当前节点的路径
		if (root == nullptr)
			return ret;
		func(ret, root, path);
		return ret;
	}
	vector<string> binaryTreePaths1()
	{
		vector<string> ret;
		stack<string> path;
		stack<TreeNode*> st;
		st.push(root);
		path.push(to_string(root->val));
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			string s = path.top();
			path.pop();
			if (cur->left == nullptr && cur->right == nullptr)
				ret.push_back(s);
			if (cur->right)
			{
				st.push(cur->right);
				path.push(s + "->" + to_string(cur->right->val));
			}
			if (cur->left)
			{
				st.push(cur->left);
				path.push(s + "->" + to_string(cur->left->val));
			}
		}
		return ret;
	}
private:
	TreeNode* root;
};
void test()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8,9,0 };
	Mytree mt;
	mt.init(nums);
	vector<string> ret;
	ret = mt.binaryTreePaths();
	for (auto e : ret)
	{
		cout << e << endl;
	}
	ret = mt.binaryTreePaths1();
	for (auto e : ret)
	{
		cout << e << endl;
	}
}

int main()
{
	test();
	return 0;
}