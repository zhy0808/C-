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
	//后续遍历，求每一个子树是否平衡，如果平衡，返回他的高度，否则返回-1
	int gethigh(TreeNode* node)
	{
		if (node == nullptr)           //如果当前节点为空，则他的高度为0
			return 0;
		int left = gethigh(node->left);  
		if (left == -1)                //如果左子树的高度为-1，说明左子树不平衡，直接返回-1
			return -1;
		int right = gethigh(node->right);
		if (right == -1)               //如果右子树的高度为-1，说明右子树不平衡，直接返回-1
			return -1;
		if (abs(left - right) > 1)     //如果左右子树都平衡，但是他们的高度差大于1，说明以该节点为根的子树不平衡，返回-1
			return -1;
		else                           //如果左右子树都平衡，且左右子树高度差小于1，说明以该节点为根的子树平衡，返回该子树的高度，即左右子树较高的一个加上1
			return max(left, right) + 1;
	}

	bool isBalanced()
	{
		if (root == nullptr)
			return true;
		if (gethigh(root) == -1)        //如果根节点的高度小于1，说明不平衡
			return false;
		else                            //否则，得到的是该树的高度
			return true;
	}

private:
	TreeNode* root;
};

void test()
{
	Mytree mt;
	vector<int> v = { 1,2,3,4,5,6,7 };
	mt.init(v);
	cout << mt.isBalanced() << endl;
}


int main()
{

	test();
	return 0;
}