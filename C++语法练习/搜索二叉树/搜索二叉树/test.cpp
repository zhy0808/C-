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
	t.insert("insert", "²åÈë");
	t.insert("erase", "É¾³ı");
	t.insert("left", "×ó±ß");
	t.insert("string", "×Ö·û´®");
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
			cout << "µ¥´ÊÆ´Ğ´´íÎó" << endl;
		}
	}*/
	t.inorder();
	vector<string> v = { "Æ»¹û","Àæ","ÌÒ","èÖ×Ó","Æ»¹û","Ïã½¶","ÌÒ","èÖ×Ó","Æ»¹û","ÆÏÌÑ" };
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