#include <iostream>
#include <vector>
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
	vector<int> largestValues()
	{
		vector<int> ret;
		if(root == nullptr)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			int max = q.front()->val;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				max = max >= cur->val ? max : cur->val;
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			ret.push_back(max);
		}
		return ret;
	}
private:
	TreeNode* root;
};


void test()
{
	Mytree mt;
	vector<int> v = { 1,3,2,5,3,9 };
	mt.init(v);
	vector<int> ret;
	ret = mt.largestValues();
	for (int i : ret)
	{
		cout << i << " ";
	}
	cout << endl;
}
int main()
{

	test();
	return 0;
}