#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct TreeNode
{
	char pixel;       //记录当前节点代表的字符（父节点不表示任何字符）
	int count;        //记录当前节点的出现次数
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(char p = ' ', int c = 0, TreeNode* l = nullptr, TreeNode* r = nullptr)
		:pixel(p)
		, count(c)
		, left(l)
		, right(r)
	{

	}
	bool operator<(const TreeNode& cur) const       //下面排序用到了优先级队列，这里的节点比较是根据count来比较，所以要重载比较运算符
	{
		return count > (cur.count);
	}
	/*bool operator>(const TreeNode* cur)
	{
		return cur->count < count;
	}*/
};

//初始化所有节点
void initTreeNode(priority_queue<TreeNode>& pq, int nodeSum)
{
	for (int i = 1; i <= nodeSum; i++)
	{
		char c;
		int num;
		cout << "请输入第" << i << "等级亮度的符号及出现次数：";
		cin >> c >> num; 
		//把每个等级亮度的对应字母及其出现次数构建一个节点，并把这个节点存入优先级队列
		TreeNode node(c, num);   
		pq.push(node);
	}
}



class HFMTree
{
public:
	//将初始化好的所有节点生成一颗哈夫曼树
	void init(priority_queue<TreeNode>& q)
	{
		while (q.size() != 1)   //如果优先级队列当前大小不为1，等于1说明队列中就剩一个根节点
		{
			//取两次优先级队列堆顶的元素，这两个是所有节点中count最小的两个
			//用这两个节点为左右孩子，生成一个父节点，把父节点push进优先级队列
			TreeNode* left = new TreeNode(q.top());
			q.pop();
			TreeNode* right = new TreeNode(q.top());
			q.pop();
			TreeNode parent(' ', left->count + right->count, left, right);
			q.push(parent);
		}
		root = new TreeNode(q.top());
	}
	//打印哈夫曼树中的所有叶子节点对应的编码
	void printCode()
	{
		string code;
		print(code, root);
	}
private:
	TreeNode* root;
	void print(string s, TreeNode* cur)
	{
		//s记录路径对应的编码，做路径编码为0，右路径编码为1
		//如果当前节点是孩子节点，打印该节点的字母及其对应的编码
		if (cur->left == nullptr && cur->right == nullptr)
		{
			cout << cur->pixel << ":" << s << endl;
			return;
		}
		//如果当前节点的左孩子不为空，进入左孩子，路径加上0（注意，这里是将路径加0递归进去，没有改变这一层的路径，当递归返回时，即构成了回溯）
		if (cur->left)
		{
			print(s + '0', cur->left);
		}
		if (cur->right)
		{
			print(s + '1', cur->right);
		}
	}
};



void test()
{
	priority_queue<TreeNode> pq;
	int nodeSum = 0;
	cout << "请输入不同等级亮度个数" << endl;
	cin >> nodeSum;
	initTreeNode(pq, nodeSum);    //记录所有亮度对应的字母及其出现的次数，用优先级队列保存
	HFMTree t;
	t.init(pq);                   //初始化哈夫曼树
	t.printCode();                //打印哈夫曼编码
	
}
int main()
{
	test();
	return 0;
}