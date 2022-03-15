#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v = 0)
		:val(v)
		, left(nullptr)
		, right(nullptr)
	{

	}
};
class mytree {
public:
	mytree()
		:root(nullptr)
	{

	}
	TreeNode* init(vector<int>& nums, int n = 0) {
		if (n >= nums.size())
			return nullptr;
		TreeNode* tmp = new TreeNode(nums[n]);
		tmp->left = init(nums, n * 2 + 1);
		tmp->right = init(nums, n * 2 + 2);
		root = tmp;
		return root;
	}
	TreeNode* getroot()
	{
		return root;
	}
private:
	TreeNode* root;
};
bool func(TreeNode* cur1, TreeNode* cur2) {
	if (cur2 == nullptr)
		return true;
	if (cur1 == nullptr || cur1->val != cur2->val)
		return false;
	if (cur1->val == cur2->val)
		return func(cur1->left, cur2->left) && func(cur1->right, cur2->right);
}
bool HasSubtree(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr || root2 == nullptr) {
		return false;
	}
	return HasSubtree(root1->left, root2) || HasSubtree(root1->right, root2) || func(root1, root2);
}
void test() {
	vector<int> nums1 = { 8,8,7,9,2,4,7 };
	vector<int> nums2 = { 8,9,2 };
	mytree t1, t2;
	t1.init(nums1);
	t2.init(nums2);
	cout << HasSubtree(t1.getroot(), t2.getroot()) << endl;
}
int main() {

	test();
	return 0;
}