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
	//������������ÿһ�������Ƿ�ƽ�⣬���ƽ�⣬�������ĸ߶ȣ����򷵻�-1
	int gethigh(TreeNode* node)
	{
		if (node == nullptr)           //�����ǰ�ڵ�Ϊ�գ������ĸ߶�Ϊ0
			return 0;
		int left = gethigh(node->left);  
		if (left == -1)                //����������ĸ߶�Ϊ-1��˵����������ƽ�⣬ֱ�ӷ���-1
			return -1;
		int right = gethigh(node->right);
		if (right == -1)               //����������ĸ߶�Ϊ-1��˵����������ƽ�⣬ֱ�ӷ���-1
			return -1;
		if (abs(left - right) > 1)     //�������������ƽ�⣬�������ǵĸ߶Ȳ����1��˵���Ըýڵ�Ϊ����������ƽ�⣬����-1
			return -1;
		else                           //�������������ƽ�⣬�����������߶Ȳ�С��1��˵���Ըýڵ�Ϊ��������ƽ�⣬���ظ������ĸ߶ȣ������������ϸߵ�һ������1
			return max(left, right) + 1;
	}

	bool isBalanced()
	{
		if (root == nullptr)
			return true;
		if (gethigh(root) == -1)        //������ڵ�ĸ߶�С��1��˵����ƽ��
			return false;
		else                            //���򣬵õ����Ǹ����ĸ߶�
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