#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v = 0, TreeNode* l = nullptr, TreeNode* r = nullptr)
		:val(v)
		, left(l)
		, right(r)
	{

	}
};

TreeNode* init(int begin, int end, vector<int>& nums)
{
	if (begin >= end)
		return nullptr;
	int rootindex = begin;
	//找每一个区间最大值，将该值作为当前子树的根
	for (int i = begin; i < end; i++)
	{
		if (nums[rootindex] < nums[i])
			rootindex = i;
	}
	TreeNode* root = new TreeNode(nums[rootindex]);
	root->left = init(begin, rootindex, nums);
	root->right = init(rootindex + 1, end, nums);
	return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
	return init(0, nums.size(),nums);
}
void test()
{
	vector<int> nums = { 3,2,1,6,0,5 };
	constructMaximumBinaryTree(nums);

}

int main()
{
	test();
	return 0;
}