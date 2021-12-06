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
//µÝ¹é,Ç°Ðò±éÀú
bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr || q == nullptr)
		return false;
	else if (p == nullptr && q == nullptr)
		return true;
	else if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//µü´ú
bool isSameTree1(TreeNode* cur1,TreeNode* cur2)
{
	if (cur1 == nullptr && cur2 == nullptr)
		return true;
	else if (cur1 == nullptr || cur2 == nullptr)
		return false;
	queue<TreeNode*> qu;
	qu.push(cur1);
	qu.push(cur2);
	while (!qu.empty())
	{
		TreeNode* left = qu.front();
		qu.pop();
		TreeNode* right = qu.front();
		qu.pop();
		if (left == nullptr && right == nullptr)
			continue;
		if ((left == nullptr || right == nullptr || (left->val != right->val)))
			return false;
		qu.push(left->left);
		qu.push(right->left);
		qu.push(left->right);
		qu.push(right->right);
	}
	return true;

}
void test()
{
	vector<int> nums1 = { 1,2,3,4,5,6,7 };
	vector<int> nums2 = { 1,1,2,3,4,5,6,7,1,2,3,4,5,6,7,8,9 };
	Mytree t1;
	Mytree t2;
	t1.init(nums1);
	t2.init(nums2);
	cout << isSameTree(t1.root, t2.root) << endl;
	cout << isSameTree1(t1.root, t2.root) << endl;
}

int main()
{
	test();
	return 0;
}