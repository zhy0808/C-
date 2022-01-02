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
		return tmp;
	}
	//������ȱ���������������
	int countNodes1()
	{
		if (root == nullptr)
			return 0;
		return func(root);
	}
	int func(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		int left = func(root->left);
		int right = func(root->right);
		return left + right + 1;
	}
	//�������
	int countNodes2()
	{
		if (root == nullptr)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int ret = 0;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				ret++;
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return ret;
	}
	//������ȫ�����������ʣ�����ȫ�������У�������ײ�ڵ����û�����⣬
	//����ÿ��ڵ������ﵽ���ֵ������������һ��Ľڵ㶼�����ڸò�����ߵ�����λ��
	int countNodes3(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int h1 = 0;              //��¼���������ĸ߶�
		int h2 = 0;
		while (left)
		{
			left = left->left;
			h1++;
		}
		while (right)
		{
			right = right->right;
			h2++;
		}
		if (h1 == h2)               //������������߶���ͬ��˵������Ϊ�������������ù�ʽ����
			return (2 << h1) - 1; 
		//������������߶Ȳ�ͬ����ֱ�������������ĸ߶ȣ��ݹ鵽����Ϊ��������Ϊֹ
		return countNodes3(root->left) + countNodes3(root->right) + 1;
	}
	TreeNode* root;
};
void test()
{
	Mytree mt;
	vector<int> v = { 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1 };
	mt.init(v);
	cout << mt.countNodes1() << endl;
	cout << mt.countNodes2() << endl;
	cout << mt.countNodes3(mt.root) << endl;

}
int main()
{
	test();
	return 0;
}