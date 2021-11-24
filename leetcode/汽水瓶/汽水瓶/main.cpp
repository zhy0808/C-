#include<iostream>
#include<windows.h>
using namespace std;
class water
{
private:
	int full;
	int empty;
	int count;
public:
	water(int _full, int _empty = 0, int _count = 0)
	{
		full = _full;
		empty = _empty;
		count = _count;
	}
	int Count()
	{
		empty = full;
		do
		{
			count += empty / 3;
			empty = empty / 3 + empty % 3;
		} while (empty > 2);
		if (empty == 2)
		{
			count++;
		}
		return count;
	}
};
int main()
{
	int f[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> f[i];
		if (f[i] == 0)
			break;
	}
	int i = 0;
	while (f[i] != 0)
	{
		water w(f[i]);
		cout << w.Count() << endl;
		i++;
	}
	system("pause");
	return 0;
}