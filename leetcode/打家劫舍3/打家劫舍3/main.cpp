#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val = 0)
		:val(_val)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
class Tree
{
public:
	Tree()
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

	TreeNode* root;
};
unordered_map<TreeNode*, int> map;
int rob3(TreeNode* root) {
	if (root == nullptr)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return root->val;
	if (map[root])
		return map[root];
	int rootval = root->val;
	if (root->left != nullptr)
		rootval += rob3(root->left->left) + rob3(root->left->right);
	if (root->right != nullptr)
		rootval += rob3(root->right->left) + rob3(root->right->right);
	int childval = rob3(root->left) + rob3(root->right);
	//记录当前节点后能偷到的最大值，防止父节点重复计算
	map[root] = max(rootval, childval);
	return max(rootval, childval);
}
void test()
{
	vector<int> nums = { 3,2,3,3,1 };
	Tree t;
	t.init(nums);
	cout << rob3(t.root) << endl;
}
int main()
{
	test();
	return 0;
}