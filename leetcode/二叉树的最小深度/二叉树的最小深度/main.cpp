#include <iostream>
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
	int minDepth()
	{
		if (root == nullptr)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int ret = 0;
		while (!q.empty())
		{
			int size = q.size();
			ret++;
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left == nullptr && cur->right == nullptr)  //�����ǰ�ڵ�û���ӽڵ㣬���ص�ǰ����������ȣ�
					return ret;
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return ret;
	}

	int func(TreeNode* root)
	{
		if (root == nullptr)      //�����ǰ�ڵ��ǿսڵ㣬����0
			return 0;
		if (root->left == nullptr || root->right == nullptr)  //�����ǰ�ڵ�����ӻ����Һ���Ϊ�գ���С��ȿ϶��ڲ�Ϊ�յ���һ�࣬���ز�Ϊ��һ�����������
		{
			//��1����Ϊ��Ҫ���ϵ�ǰ�ڵ㣬ֱ�ӽ�����������������Ϊ��һ����0
			return func(root->left) + func(root->right) + 1;
		}
		//���������������Ϊ�գ��򷵻�������������Ƚ�С�ģ���1����ΪҪ���ϸýڵ�
		return min(func(root->left), func(root->right)) + 1;
	}
	int minDepth1()
	{
		if (root == nullptr)
			return 0;
		return func(root);
	}
private:
	TreeNode* root;
};

void test()
{
	Mytree mt;
	vector<int> v = { 3,9,20,15,7 };
	mt.init(v);
	cout << mt.minDepth() << endl;
	cout << mt.minDepth1() << endl;
}
int main()
{
	test();
	return 0;
}