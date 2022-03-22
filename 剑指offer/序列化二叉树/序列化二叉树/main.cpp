#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v)
        :val(v)
        , left(nullptr)
        , right(nullptr)
    {

    }
};
char* Serialize(TreeNode* root) {
    string ret;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* cur = s.top();
        s.pop();
        if (cur == nullptr)
            ret += "#.";
        else {
            ret += to_string(cur->val) + '.';
            s.push(cur->right);
            s.push(cur->left);
        }
        //             while(size--) {
        //                 TreeNode* cur = q.front();
        //                 q.pop();
        //                 if(cur == nullptr)
        //                     ret += "#.";
        //                 else {
        //                     ret += to_string(cur->val) + '.';
        //                     q.push(cur->left);
        //                     q.push(cur->right);
        //                 }
        //             }
    }
    char* c = new char[ret.size()];
    for (int i = 0; i < ret.size(); ++i) {
        c[i] = ret[i];
    }
    return c;
}
TreeNode* Deserialize(char*& str) {
    if (*str == '#') {
        str++;
        return nullptr;
    }
    int n = 0;
    while (*str != '.') {
        n = n * 10 + *str - '0';
        str++;
    }
    TreeNode* cur = new TreeNode(n);
    cur->left = Deserialize(++str);
    cur->right = Deserialize(++str);
    return cur;
}
class mytree {
public:
    mytree()
        :root(nullptr)
    {

    }
    TreeNode* init(vector<int>& nums, int i = 0) {
        if (i >= nums.size())
            return nullptr;
        TreeNode* cur = new TreeNode(nums[i]);
        cur->left = init(nums, i * 2 + 1);
        cur->right = init(nums, i * 2 + 2);
        root = cur;
        return root;
    }
    TreeNode* getroot() {
        return root;
    }
private:
    TreeNode* root;
};
void test() {
    mytree mt;
    vector<int> nums = { 1,2,3,4,5,6,7 };
    mt.init(nums);
    char* str = Serialize(mt.getroot());
    cout << str << endl;
}
int main() {
	test();
	return 0;
}