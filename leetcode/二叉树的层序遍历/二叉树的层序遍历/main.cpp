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
		,left(nullptr)
		,right(nullptr)
	{}
};
class Mytree 
{
public:
	Mytree()
		:root(nullptr)
	{

	}
	TreeNode* init(vector<int>& nums ,int n = 0)
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
	vector<vector<int>> levelOrder()
	{
		vector<vector<int>> ret;
		if (root == nullptr)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vector<int> res;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				res.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			ret.push_back(res);
		}
		return ret;
	}
private:
	TreeNode* root;
};
void test()
{
	Mytree mt;
	vector<int> v = { 1,2,3,4,5,6,7 };
	mt.init(v);
	vector<vector<int>> vv;
	vv = mt.levelOrder();
	for (int i = 0; i < vv.size(); i++)
	{
		for (int j = 0; j < vv[i].size(); j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	test();
	return 0;
}