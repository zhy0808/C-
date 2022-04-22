#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct TreeNode
{
	char pixel;       //��¼��ǰ�ڵ������ַ������ڵ㲻��ʾ�κ��ַ���
	int count;        //��¼��ǰ�ڵ�ĳ��ִ���
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(char p = ' ', int c = 0, TreeNode* l = nullptr, TreeNode* r = nullptr)
		:pixel(p)
		, count(c)
		, left(l)
		, right(r)
	{

	}
	bool operator<(const TreeNode& cur) const       //���������õ������ȼ����У�����Ľڵ�Ƚ��Ǹ���count���Ƚϣ�����Ҫ���رȽ������
	{
		return count > (cur.count);
	}
	/*bool operator>(const TreeNode* cur)
	{
		return cur->count < count;
	}*/
};

//��ʼ�����нڵ�
void initTreeNode(priority_queue<TreeNode>& pq, int nodeSum)
{
	for (int i = 1; i <= nodeSum; i++)
	{
		char c;
		int num;
		cout << "�������" << i << "�ȼ����ȵķ��ż����ִ�����";
		cin >> c >> num; 
		//��ÿ���ȼ����ȵĶ�Ӧ��ĸ������ִ�������һ���ڵ㣬��������ڵ�������ȼ�����
		TreeNode node(c, num);   
		pq.push(node);
	}
}



class HFMTree
{
public:
	//����ʼ���õ����нڵ�����һ�Ź�������
	void init(priority_queue<TreeNode>& q)
	{
		while (q.size() != 1)   //������ȼ����е�ǰ��С��Ϊ1������1˵�������о�ʣһ�����ڵ�
		{
			//ȡ�������ȼ����жѶ���Ԫ�أ������������нڵ���count��С������
			//���������ڵ�Ϊ���Һ��ӣ�����һ�����ڵ㣬�Ѹ��ڵ�push�����ȼ�����
			TreeNode* left = new TreeNode(q.top());
			q.pop();
			TreeNode* right = new TreeNode(q.top());
			q.pop();
			TreeNode parent(' ', left->count + right->count, left, right);
			q.push(parent);
		}
		root = new TreeNode(q.top());
	}
	//��ӡ���������е�����Ҷ�ӽڵ��Ӧ�ı���
	void printCode()
	{
		string code;
		print(code, root);
	}
private:
	TreeNode* root;
	void print(string s, TreeNode* cur)
	{
		//s��¼·����Ӧ�ı��룬��·������Ϊ0����·������Ϊ1
		//�����ǰ�ڵ��Ǻ��ӽڵ㣬��ӡ�ýڵ����ĸ�����Ӧ�ı���
		if (cur->left == nullptr && cur->right == nullptr)
		{
			cout << cur->pixel << ":" << s << endl;
			return;
		}
		//�����ǰ�ڵ�����Ӳ�Ϊ�գ��������ӣ�·������0��ע�⣬�����ǽ�·����0�ݹ��ȥ��û�иı���һ���·�������ݹ鷵��ʱ���������˻��ݣ�
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
	cout << "�����벻ͬ�ȼ����ȸ���" << endl;
	cin >> nodeSum;
	initTreeNode(pq, nodeSum);    //��¼�������ȶ�Ӧ����ĸ������ֵĴ����������ȼ����б���
	HFMTree t;
	t.init(pq);                   //��ʼ����������
	t.printCode();                //��ӡ����������
	
}
int main()
{
	test();
	return 0;
}