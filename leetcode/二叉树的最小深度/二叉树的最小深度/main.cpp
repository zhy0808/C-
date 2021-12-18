#include <iostream>
#include <queue>
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
	int minDepth()
	{
		if (root == nullptr)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int ret = 0;
		while (!q.empty())
		{
			int size = q.size();
			ret++;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left == nullptr && cur->right == nullptr)  //如果当前节点没有子节点，返回当前层数（即深度）
					return ret;
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return ret;
	}

	int func(TreeNode* root)
	{
		if (root == nullptr)      //如果当前节点是空节点，返回0
			return 0;
		if (root->left == nullptr || root->right == nullptr)  //如果当前节点的左孩子或者右孩子为空，最小深度肯定在不为空的那一侧，返回不为空一侧子树的深度
		{
			//加1是因为还要算上当前节点，直接将两子树深度相加是因为有一侧是0
			return func(root->left) + func(root->right) + 1;
		}
		//如果两个子树都不为空，则返回他们两个中深度较小的，加1是因为要算上该节点
		return min(func(root->left), func(root->right)) + 1;
	}
	int minDepth1()
	{
		if (root == nullptr)
			return 0;
		return func(root);
	}
private:
	TreeNode* root;
};

void test()
{
	Mytree mt;
	vector<int> v = { 3,9,20,15,7 };
	mt.init(v);
	cout << mt.minDepth() << endl;
	cout << mt.minDepth1() << endl;
}
int main()
{
	test();
	return 0;
}