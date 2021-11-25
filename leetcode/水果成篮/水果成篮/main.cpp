#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

int totalFruit(vector<int>& fruits) {
	size_t lift = 0, right = 0;       //�������ڵ����ұ߽�
	int basket1, basket2;         //��������
	basket1 = basket2 = fruits[0];   //��ʼ��������ֻ��װfruits[0]��ˮ��
	int ans = 1;                   //�������ռ�ˮ�������������
	while (right < fruits.size())   //�ұ�û������ͣ����
	{
		if (fruits[right] != basket1 && fruits[right] != basket2)//����ұ����ϵ�ˮ����������������װ�Ķ���ͬ
		{
			lift = right - 1;        //�����������λ�ã��ѵ�ǰ������ˮ�����ͷ�������
			basket1 = fruits[lift];
			basket2 = fruits[right];
			while (lift > 0 && fruits[lift - 1] == basket1)//������ǰ����û�����ڵ�ͬ���͹���
			{
				lift--;
			}
		}
		int len = right - lift + 1;    //��ǰװ�����ӵĹ�������
		ans = ans >= len ? ans : len;    //����һ�����ռ����Ĺ������������ȣ�������͸���
		right++;                 //�����ж���һ����
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