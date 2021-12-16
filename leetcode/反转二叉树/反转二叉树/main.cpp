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
	TreeNode* invertTree(TreeNode* node)
	{
		if (node == nullptr)
			return nullptr;
		swap(node->left, node->right);    //交换当前节点的左右孩子
		invertTree(node->left);           //对左右孩子进行同样操作
		invertTree(node->right);
		return node;
	}
private:
	TreeNode* root;
};

void test()
{
	Mytree mt;
	vector<int> v = { 4,2,7,1,3,6,9 };
	mt.init(v);
}
int main()
{
	test();
	return 0;
}