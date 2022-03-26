#include "RBTree.hpp"
RBTree::RBTree() {
	head = new TreeNode();
}
bool RBTree::insert(int v){
	if (head->parent == nullptr) {
		TreeNode* root = new TreeNode(v, black);
		root->parent = head;
		head->parent = root;
		return true;
	}
	else {
		TreeNode* node = new TreeNode(v, red);
		TreeNode* cur = head->parent;
		TreeNode* p = nullptr;
		while (cur) {
			p = cur;
			if (node->_val < cur->_val) {
				cur = cur->left;
			}
			else if (node->_val > cur->_val) {
				cur = cur->right;
			}
			else
				return false;
		}
		//���½ڵ��������
		if (p->_val > node->_val) {
			p->left = node;
			node->parent = p;
		}
		else {
			p->right = node;
			node->parent = p;
		}
		//�жϵ�ǰ���ṹ�Ƿ�Ϸ�
		if (p->_color == black)
			return true;
		//���Ϸ�������
		while(node->parent != head && node->parent->_color == red) {
			TreeNode* grandparent = node->parent->parent;
			if (node->parent == grandparent->left) {
				TreeNode* uncle = grandparent->right;
				//���Ϸ���4�ڵ㣬��Ҫ��4�ڵ��м��������Ϊ�ڽڵ�
				if (uncle == nullptr) {
					//��ǰ�����ṹΪ���ң�Ҫ������������
					//��ǰ�����ṹΪ����ֱ������
					if (node == node->parent->right) {
						Lrotate(node->parent);
						node = node->left;
					}
					node->parent->_color = black;
					grandparent->_color = red;
					Rrotate(grandparent);
				}
				//��4�ڵ������ֵ����Ҫ��������
				else {
					node->parent->_color = black;
					uncle->_color = black;
					grandparent->_color = red;
					node = grandparent;
				}
			}
			else {
				TreeNode* uncle = grandparent->left;
				//���Ϸ���4�ڵ㣬��Ҫ��4�ڵ��м��������Ϊ�ڽڵ�
				if (uncle == nullptr) {
					if (node == node->parent->left) {
						Rrotate(node->parent);
						node = node->right;
					}
					node->parent->_color = black;
					grandparent->_color = red;
					Lrotate(grandparent);
				}
				//��4�ڵ������ֵ����Ҫ��������
				else {
					node->parent->_color = black;
					uncle->_color = black;
					grandparent->_color = red;
					node = grandparent;
				}
			}
			head->parent->_color = black;
		}
		return true;

	}
}
void RBTree::count(int path, TreeNode* cur) {
	if (cur->left == nullptr && cur->right == nullptr) {
		cout << path << endl;
		return;
	}
	if (cur->left) {
		if (cur->left->_color == black) {
			count(path + 1, cur->left);
		}
		else
			count(path, cur->left);
	}
	if (cur->right) {
		if (cur->right->_color == black)
			count(path + 1, cur->right);
		else
			count(path, cur->right);
	}
	
}
void RBTree::blackCount() {
	int path = 1;
	count(path, head->parent);
}
void RBTree::i(TreeNode* cur) {
	if (cur == nullptr)
		return;
	i(cur->left);
	//cout << cur->_val << endl;
	if (cur->_color == red && cur->parent->_color == red)
		cout << "����������������ڵ�" << endl;
	i(cur->right);
}
void RBTree::inorder() {
	stack<TreeNode*> st;
	TreeNode* cur = head->parent;
	st.push(head->parent);
	while (!st.empty() || cur) {
		if (cur != nullptr) {
			st.push(cur);
			cur = cur->left;
		}
		else {
			cur = st.top();
			st.pop();
			cout << cur->_val << endl;
			cur = cur->right;
		}
	}
	//i(head->parent);
}


//�ѵ�ǰ�ڵ�����
void RBTree::Lrotate(TreeNode* cur) {
	TreeNode* P = cur->parent;
	if (P == head) {
		P->parent = cur->right;
	}
	else {
		if (cur == P->left)
			P->left = cur->right;
		else
			P->right = cur->right;
	}
	
	cur->right->parent = P;
	cur->right->left = cur;
	cur->parent = cur->right;
	cur->right = nullptr;
	
}
//�ѵ�ǰ�ڵ�����
void RBTree::Rrotate(TreeNode* cur) {
	TreeNode* P = cur->parent;
	//�����ǰ�ڵ�ĸ��ڵ���ͷ�ڵ㣬��ͷ�ڵ�ĸ��ڵ�ָ��ǰ�ڵ������
	if (P == head) {
		P->parent = cur->left;
		
	}
	else {
		if (cur == P->left)
			P->left = cur->left;
		else
			P->right = cur->left;
	}
	//�ѵ�ǰ�ڵ���ת�����ӵ��Һ���
	
	cur->left->parent = P;
	cur->left->right = cur;
	cur->parent = cur->left;
	cur->left = nullptr;
	
}
