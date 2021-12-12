#include<iostream>
#include<vector>
using namespace std;
#include<windows.h>
class Gift
{
public:
	int getValueu(vector<int> gifts, int n)
	{
		int arr[] = { 0 };
		for (int i = 0; i<n; i++)
		{
			arr[gifts[i] % n - 1]++;
			if (arr[gifts[i] % n]>n)
				return gifts[i];
		}
		return 0;
	}
};

int main()
{

	Gift g;
	int arr[] = { 1, 2, 3, 2, 2 };

	g.getValue(arr, 5);
	system("pause");
	return 0;
}