#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node 
{
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node()
		:val(0)
		, left(nullptr)
		, right(nullptr)
		, next(nullptr)
	{

	}
};
class Mytree
{
public:
	Mytree()
		:root(nullptr)
	{}
	Node* init(vector<int> nums, int n = 0)
	{
		if (n >= nums.size())
			return nullptr;
		Node* tmp = new Node();
		tmp->val = nums[n];
		tmp->left = init(nums, n * 2 + 1);
		tmp->right = init(nums, n * 2 + 2);
		root = tmp;
		return root;
	}
	Node* connect()
	{
		if (root == nullptr)
			return root;
		queue<Node*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				Node* cur = q.front();
				q.pop();
				if (i < size - 1)   //当前节点不是当前层的最后一个节点，当前节点的next指向它相邻的节点
					cur->next = q.front();
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
		return root;
	}
private:
	Node* root;
};
void test()
{
	Mytree mt;
	vector<int> v = { 1,2,3,4,5,6,7 };
	mt.connect();
}
int main()
{
	test();
	return 0;
}