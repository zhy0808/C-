#include <iostream>
#include <vector>
using namespace std;
struct Tnode
{
	int val;
	Tnode* left;
	Tnode* right;
	Tnode(int v = 0)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
Tnode* init(vector<int>& nums, int left, int right)
{
	if (left > right)
		return nullptr;
	//确定根节点在数组中的下标
	int rootindex = (left + right) / 2;
	//构建根节点
	Tnode* node = new Tnode(nums[rootindex]);
	//左子树用数组中根节点值的左半部分构造
	node->left = init(nums, left, rootindex - 1);
	//右子树用数组中根节点值的右半部分构造
	node->right = init(nums, rootindex + 1, right);
	return node;
}
Tnode* sortedArrayToBST(vector<int>& nums)
{
	Tnode* root = init(nums, 0, nums.size() - 1);
	return root;
}
void inorder(Tnode* cur)
{
	if (cur == nullptr)
		return;
	inorder(cur->left);
	cout << cur->val << endl;
	inorder(cur->right);
}
void test()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
	Tnode* root = sortedArrayToBST(nums);
	inorder(root);
}
int main()
{
	test();
	return 0;
}