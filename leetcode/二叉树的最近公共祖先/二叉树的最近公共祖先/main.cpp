#include <iostream>
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
	TreeNode* lowestCommonAncestor(int p, int q)
	{
		return find(root, p, q);
	}
private:
	TreeNode* root;
	//后续遍历
	TreeNode* find(TreeNode* cur, int p, int q)
	{
		//如果当前节点为空，或者当前节点值等于p或q，就返回当前节点
		if (cur == nullptr || cur->val == p || cur->val == q)
			return cur;
		//在左子树和右子树中找与p、q值相等的点，找到了就返回这个点，没找到就返回空
		TreeNode* left = find(cur->left, p, q);
		TreeNode* right = find(cur->right, p, q);
		//如果在左右子树分别找到了p或q，则该节点就是他们最近的公共父节点
		if (left != nullptr && right != nullptr)
			return cur;
		//如果左子树找到了p或q，右子树没找到，则返回左子树找到的这个节点，表示找到了p或q其中一个
		if (left != nullptr && right == nullptr)
			return left;
		else if (left == nullptr && right != nullptr)
			return right;
		//如果左右子树都没找到，返回空，表示当前子树中不存在p或q
		else
			return nullptr;
	}
};


void test()
{
	vector<int> nums = { 1,2,3,4,5,6,7,8 };
	Mytree t;
	t.init(nums);
	TreeNode* ret = t.lowestCommonAncestor(4, 7);
	cout << ret->val << endl;
}


int main()
{

	test();
	return 0;
}