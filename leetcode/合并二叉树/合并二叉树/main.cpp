#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v = 0, TreeNode* l = nullptr, TreeNode* r = nullptr)
		:val(v)
		, left(l)
		, right(r)
	{

	}
};

TreeNode* init(int begin, int end, vector<int>& nums)
{
	if (begin >= end)
		return nullptr;
	int rootindex = begin;
	//��ÿһ���������ֵ������ֵ��Ϊ��ǰ�����ĸ�
	for (int i = begin; i < end; i++)
	{
		if (nums[rootindex] < nums[i])
			rootindex = i;
	}
	TreeNode* root = new TreeNode(nums[rootindex]);
	root->left = init(begin, rootindex, nums);
	root->right = init(rootindex + 1, end, nums);
	return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
	return init(0, nums.size(), nums);
}



//����
TreeNode* mergeTree1(TreeNode* root1, TreeNode* root2)
{
	if (root1 == nullptr)
		return root2;
	if (root2 == nullptr)
		return root1;
	queue<TreeNode*> q;
	q.push(root1);
	q.push(root2);
	while (!q.empty())
	{
		TreeNode* cur1 = q.front();
		q.pop();
		TreeNode* cur2 = q.front();
		q.pop();
		cur1->val += cur2->val;    //���������ڵ㶼��Ϊ�գ�ֱ��������
		if (cur1->left != nullptr && cur2->left != nullptr)  //����������ڵ�ĺ��ӽڵ㶼��Ϊ�գ��ֱ����
		{
			q.push(cur1->left);
			q.push(cur2->left);
		}
		if (cur1->right != nullptr && cur2->right != nullptr)
		{
			q.push(cur1->right);
			q.push(cur2->right);
		}
		if (cur1->left == nullptr && cur2->left != nullptr) //���root1һ������Ϊ�ն�root2��Ӧ�ĺ��Ӳ�Ϊ�գ���ֵ
			cur1->left = cur2->left;
		if (cur1->right == nullptr && cur2->right != nullptr)
			cur1->right = cur2->right;
	}
	return root1;
}
//�ݹ�
TreeNode* mergeTree2(TreeNode* root1, TreeNode* root2)
{
	if (root1 == nullptr)
		return root2;
	if (root2 == nullptr)
		return root1;
	root1->val += root2->val;
	if (root1->left != nullptr && root2->left != nullptr)
		mergeTree2(root1->left, root2->left);
	if (root1->right != nullptr && root2->right != nullptr)
		mergeTree2(root1->right, root2->right);
	if (root1->left == nullptr && root2->left != nullptr)
		root1->left = root2->left;
	if (root1->right == nullptr && root2->right != nullptr)
		root1->right = root2->right;
	return root1;
}
void test()
{
	vector<int> nums1 = { 3,2,1,6,0,5 };
	vector<int> nums2 = { 3,5,2,7,9,1,4,6 };
	//�����������������������
	//�������ĸ��������е����Ԫ�ء�
	//��������ͨ�����������ֵ��߲��ֹ����������������
	//��������ͨ�����������ֵ�ұ߲��ֹ����������������
	TreeNode* root1 = constructMaximumBinaryTree(nums1);    
	TreeNode* root2 = constructMaximumBinaryTree(nums2);
	//�ϲ�������
	mergeTree1(root1, root2);
	mergeTree2(root1, root2);

}
int main()
{
	test();
	return 0;
}