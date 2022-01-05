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
	//��������
	TreeNode* find(TreeNode* cur, int p, int q)
	{
		//�����ǰ�ڵ�Ϊ�գ����ߵ�ǰ�ڵ�ֵ����p��q���ͷ��ص�ǰ�ڵ�
		if (cur == nullptr || cur->val == p || cur->val == q)
			return cur;
		//����������������������p��qֵ��ȵĵ㣬�ҵ��˾ͷ�������㣬û�ҵ��ͷ��ؿ�
		TreeNode* left = find(cur->left, p, q);
		TreeNode* right = find(cur->right, p, q);
		//��������������ֱ��ҵ���p��q����ýڵ������������Ĺ������ڵ�
		if (left != nullptr && right != nullptr)
			return cur;
		//����������ҵ���p��q��������û�ҵ����򷵻��������ҵ�������ڵ㣬��ʾ�ҵ���p��q����һ��
		if (left != nullptr && right == nullptr)
			return left;
		else if (left == nullptr && right != nullptr)
			return right;
		//�������������û�ҵ������ؿգ���ʾ��ǰ�����в�����p��q
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