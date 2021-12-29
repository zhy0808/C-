#include <iostream>
#include <queue>
#include <vector>
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


	TreeNode* root;
};
bool compare(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
		return true;
	else if (left == nullptr || right == nullptr || (left->val != right->val))
		return false;
	return compare(left->left, right->left) && compare(left->right, right->right);
}
bool isSubTree(TreeNode* root, TreeNode* subRoot)
{
	if (root == nullptr)
		return false;
	return compare(root, subRoot) || isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}
void test()
{
	vector<int> nums1 = { 1,2,3,4,5 };
	vector<int> nums2 = { 2,4,5 };
	Mytree t1;
	Mytree t2;
	t1.init(nums1);
	t2.init(nums2);
	cout << isSubTree(t1.root, t2.root) << endl;
}
int main()
{

	test();
	return 0;
}