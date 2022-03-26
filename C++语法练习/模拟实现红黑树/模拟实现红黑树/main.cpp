#include "RBTree.hpp"

void test() {
	RBTree rbt;
	rbt.insert(5);
	rbt.insert(4);
	rbt.insert(6);
	rbt.insert(3);
	rbt.insert(7);
	rbt.insert(2);
	rbt.insert(8);
	rbt.insert(1);
	rbt.insert(9);
	rbt.insert(0);
	//rbt.inorder();
	rbt.blackCount();
}
int main() {
	test();
	return 0;
}