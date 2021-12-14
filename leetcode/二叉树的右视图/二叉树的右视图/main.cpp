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
	TreeNode* init(vector<int> nums, int n = 0)
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
	vector<int> rightSideView()
	{
		vector<int> ret;
		if (root == nullptr)
			return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				if (i == size - 1)                //��������ǰ������һ��Ԫ�أ�����
					ret.push_back(cur->val);
				if (cur->left)                    //����һ�����
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return ret;
	}
private:
	TreeNode* root;
};
void test()
{
	Mytree mt;
	vector<int> v = { 1,2,3,5,4 };
	mt.init(v);
	vector<int> ret;
	ret = mt.rightSideView();
	for (int e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test();
	return 0;
}