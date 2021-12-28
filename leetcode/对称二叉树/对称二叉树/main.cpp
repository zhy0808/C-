#include <iostream>
#include <vector>
#include <queue>
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
	bool compare(TreeNode* left, TreeNode* right)
	{
		//递归时要同时递归左右两子树，比较内外侧节点的情况
		//比较左右两边的节点情况，判断是否为空，是否相等，注意这里的左右不是左右子树，而是根节点左右子树的内侧和外侧
		if (left == nullptr && right != nullptr)     
			return false;
		else if (left != nullptr && right == nullptr)
			return false;
		else if (left == nullptr && right == nullptr)
			return true;
		else if (left->val != right->val)
			return false;
		bool w = compare(left->left, right->right); //比较外侧的子节点
		bool n = compare(left->right, right->left); //比较内测的子节点
		return w && n;  //如果内外都相等，返回true否则返回false
	}
	bool isSymmetric()
	{
		if (root == nullptr)
			return true;
		return compare(root->left, root->right);
	}

	bool isSymmetric1()
	{
		if (root == nullptr)
			return true;
		stack<TreeNode*> st;
		st.push(root->right);
		st.push(root->left);
		while (!st.empty())
		{
			TreeNode* left = st.top();
			st.pop();
			TreeNode* right = st.top();
			st.pop();
			if (left == nullptr && right != nullptr)
				return false;
			else if (left != nullptr && right == nullptr)
				return false;
			else if (left == nullptr && right == nullptr)
				continue;
			else if (left->val != right->val)
				return false;
			else
			{
				st.push(right->left);
				st.push(left->right);
				st.push(right->right);
				st.push(left->left);
			}
		}
		return true;

	}
private:
	TreeNode* root;
};
void test()
{
	Mytree mt;
	vector<int> v = { 1,2,2,3,4,4,3 };
	mt.init(v);
	cout << mt.isSymmetric() << endl;
	cout << mt.isSymmetric1() << endl;
}
int main()
{
	test();
	return 0;
}