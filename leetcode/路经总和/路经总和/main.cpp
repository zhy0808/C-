#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
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
	/*void Preorder()
	{
		_preorder(root);
	}*/

	bool hasPathSum(int targetsum)
	{
		if (root == nullptr)        
			return false;
		int sum = 0;         //记录从当前节点之前路径上val的和
		return find(root, targetsum, sum);
	}
	bool hasPathSum1(int tar)
	{
		if (root == nullptr)
			return false;
		stack<pair<TreeNode*, int>> s;
		s.push(pair<TreeNode*, int>(root, root->val));
		while (!s.empty())
		{
			pair<TreeNode*, int> node = s.top();
			s.pop();
			if (node.first->left == nullptr && node.first->right == nullptr && node.second == tar)
				return true;
			if (node.first->right)
				s.push(pair<TreeNode*,int>(node.first->right, node.second + node.first->right->val));
			if (node.first->left)
				s.push(pair<TreeNode*,int>(node.first->left, node.second + node.first->left->val));
		}
		return false;
	}
private:
	TreeNode* root;
	bool find(TreeNode* cur, int targent, int sum)
	{
		if (cur->left == nullptr && cur->right == nullptr)
		{
			//如果当前节点是叶子节点，且与targent值相等，说明找到了
			if (sum+cur->val == targent)
				return true;
			else
				return false;
		}
		bool left = false;
		bool right = false;
		if (cur->left)         //左子树不为空，进左子树找叶子节点，
			left = find(cur->left, targent, sum + cur->val);
		if (cur->right)        //右子树不为空，进右子树找叶子节点
			right = find(cur->right, targent, sum + cur->val);
		return left || right;
	}
	/*void _preorder(TreeNode* cur)
	{
		if (cur == nullptr)
			return;
		cout << cur->val << endl;
		_preorder(cur->left);
		_preorder(cur->right);
	}*/
};
void test()
{
	vector<int> nums = { 1,2,3,4,5,6,7 };
	Mytree t;
	t.init(nums);
	cout << t.hasPathSum(7) << endl;
	cout << t.hasPathSum1(7) << endl;
	//t.Preorder();
}
int main()
{

	test();
	return 0;
}