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
	vector<double> averageOfLevels()
	{
		vector<double> ret;
		if (root == nullptr)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())                   //层序遍历，将每一层的值加起来，最后求平均值后存入ret
		{
			int size = q.size();
			double sum = 0;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				sum += cur->val;            //算每一层的和
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			ret.push_back(sum / size);      //存入平均值
		}
		return ret;
	}
private:
	TreeNode* root;
};


void test()
{
	Mytree mt;
	vector<int> v = { 3,9,20,15,7 };
	mt.init(v);
	vector<double> ret;
	ret = mt.averageOfLevels();
	for (double d : ret)
	{
		cout << d << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}