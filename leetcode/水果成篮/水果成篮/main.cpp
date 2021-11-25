#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

int totalFruit(vector<int>& fruits) {
	size_t lift = 0, right = 0;       //滑动窗口的左右边界
	int basket1, basket2;         //两个篮子
	basket1 = basket2 = fruits[0];   //开始两个篮子只能装fruits[0]类水果
	int ans = 1;                   //现在能收集水果树的最大总量
	while (right < fruits.size())   //右边没有树就停下来
	{
		if (fruits[right] != basket1 && fruits[right] != basket2)//如果右边树上的水果类型与两个篮子装的都不同
		{
			lift = right - 1;        //更新左边树的位置，把当前左右树水果类型放入篮子
			basket1 = fruits[lift];
			basket2 = fruits[right];
			while (lift > 0 && fruits[lift - 1] == basket1)//找左树前面有没有相邻的同类型果树
			{
				lift--;
			}
		}
		int len = right - lift + 1;    //当前装进篮子的果树总量
		ans = ans >= len ? ans : len;    //与上一次能收集到的果树最大总量相比，比他大就更新
		right++;                 //继续判断下一个树
	}
	return ans;

}
int main()
{
	vector<int> fruits;
	fruits = { 1, 2, 3, 4, 5, 6, 7 };
	cout << totalFruit(fruits) << endl;
	system("pause");
	return 0;
}