#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
enum Color{red, black};
struct TreeNode {
	int _val;
	Color _color;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int v = 0, Color c = red)
		:_val(v)
		, _color(c)
		, left(nullptr)
		, right(nullptr)
		, parent(nullptr){}
};

class RBTree {
public:
	RBTree();
	bool insert(int v);
	void inorder();
	void blackCount();
private:
	void Rrotate(TreeNode* cur);
	void Lrotate(TreeNode* cur);
	void i(TreeNode* cur);
	void count(int path, TreeNode* cur);
	TreeNode* head;
};