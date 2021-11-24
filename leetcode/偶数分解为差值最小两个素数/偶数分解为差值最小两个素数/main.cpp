#include<iostream>
#include<windows.h>
using namespace std;
int S(int n)
{
	for (int i = 2; i<n; i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
void Func(int a)
{
	int b = a / 2;
	int i;
	for (i = b; i>0; --i)
	{
		if (S(i) && S(a - i))
			break;
	}
	cout << i << endl << a - i << endl;
}
int main()
{
	int a;
	cin >> a;
	if (a % 2 != 0 || a == 0)
		return false;
	Func(a);
	system("pause");
	return 0;
}