#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
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
	void find(TreeNode* cur, int tar, vector<vector<int>>& ret, vector<int>& path)
	{
		if (cur->left == nullptr && cur->right == nullptr)
		{
			int res = 0;  //���㵱ǰ·������ֵ�ĺ�
			for (int i = 0; i < path.size(); i++)
			{
				res += path[i];
			}
			if (res == tar)  //�������tar���Ͱѵ�ǰ·������ֵ����ret
				ret.push_back(path);
			return;
		}
		if (cur->left)
		{
			path.push_back(cur->left->val);
			find(cur->left, tar, ret, path);
			path.pop_back();  //������������Ҫ��������������path�е�ֵ��������
		}
		if (cur->right)
		{
			path.push_back(cur->right->val);
			find(cur->right, tar, ret, path);
			path.pop_back();
		}
	}
	vector<vector<int>> pathSum(int tar)
	{
		vector<vector<int>> ret;
		if (root == nullptr)
			return ret;
		vector<int> path;   //��¼·���ϵ�ֵ
		path.push_back(root->val);
		find(root, tar, ret, path);
		return ret;
	}
private:
	TreeNode* root;
};
void test()
{
	vector<int> nums = { 5,4,8,11,12,13,4,7,2,6,9,6,3,5,1 };
	Mytree t;
	t.init(nums);
	vector<vector<int>> ret;
	ret = t.pathSum(22);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}



int main()
{
	test();
	return 0;
}