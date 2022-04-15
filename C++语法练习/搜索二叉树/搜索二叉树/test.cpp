#include<iostream>
#include<vector>
#include "BSTree.h"
//void BSTreeVtest()
//{
//	BSTree<int> t;
//	t.insert(5);
//	t.insert(8);
//	t.insert(3);
//	t.insert(1);
//	t.insert(9);
//	t.insert(9);
//	t.Inorder();
//	t.find(3);
//	t.find(0);
//	t.erase(5);
//	t.Inorder();
//}
void test()
{
	BSTree<string, string> t;
	t.insert("insert", "����");
	t.insert("erase", "ɾ��");
	t.insert("left", "���");
	t.insert("string", "�ַ���");
	/*string s;
	while (cin >> s)
	{
		TreeNode<string, string>* ret = t.find(s);
		if (ret)
		{
			cout << s << ":" << ret->_val << endl;
		}
		else
		{
			cout << "����ƴд����" << endl;
		}
	}*/
	t.inorder();
	vector<string> v = { "ƻ��","��","��","����","ƻ��","�㽶","��","����","ƻ��","����" };
	BSTree<string, int> countTree;
	for (auto e : v)
	{
		TreeNode<string, int>* cur = countTree.find(e);
		if (cur)
		{
			cur->_val++;
		}
		else
		{
			countTree.insert(e, 1);
		}
	}
	countTree.inorder();
}
int main()
{
	//BSTreeVtest();
	test();
	return 0;
}