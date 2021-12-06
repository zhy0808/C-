#include <iostream>
#include <vector>
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
		{
			return nullptr;
		}
		TreeNode* tmp = new TreeNode();
		tmp->val = nums[n];
		tmp->left = init(nums, n * 2 + 1);
		tmp->right = init(nums, n * 2 + 2);
		root = tmp;
		return root;
	}
	int sum(TreeNode* cur)
	{
		if (cur == nullptr)
			return 0;
		int left = 0, right = 0;//记录左右子树中左叶子节点的值
		//如果当前节点的左孩子是叶子节点，左子树中左叶子节点的值就为这个左孩子的值，继续进入右子树找
		if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right == nullptr)
		{
			left = cur->left->val;
			right = sum(cur->right);
		}
		//当前节点的左孩子不是叶子节点，进入他的左右子树找
		else
		{
			left = sum(cur->left);
			right = sum(cur->right);
		}
		//将左子树和右子树中左叶子节点的值加起来
		return left + right;
	}
	int sumOfLeftLeaves()
	{
		return sum(root);
	}
	int sumOfLeftLeaves1()
	{
		if (root == nullptr)
			return 0;
		stack<TreeNode*> s;
		s.push(root);
		int ret = 0;
		while (!s.empty())
		{
			TreeNode* cur = s.top();
			s.pop();
			if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right == nullptr)
			{
				ret += cur->left->val;
				if (cur->right)
					s.push(cur->right);
			}
			else
			{
				if (cur->right)
					s.push(cur->right);
				if (cur->left)
					s.push(cur->left);
			}
		}
		return ret;
	}
private:
	TreeNode* root;
};
void test()
{
	vector<int> nums = { 1,2,3,4,5,6,7 };
	Mytree mt;
	mt.init(nums);
	cout << mt.sumOfLeftLeaves() << endl;
	cout << mt.sumOfLeftLeaves1() << endl;
}

int main()
{
	test();
	return 0;
}