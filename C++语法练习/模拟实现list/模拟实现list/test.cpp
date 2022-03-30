#include <windows.h>
#include "list.hpp"

namespace zhy{
	void Print(const list<int>& lt)
	{
		/*list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << std::endl;
			++it;
		}*/
		for (auto e : lt)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
	void test1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		Print(lt);
		lt.insert(lt.end(), 5);
		Print(lt);
		lt.erase(lt.begin());
		Print(lt);
		lt.erase(--(lt.end()));
		//lt.erase(lt.end());         //这两种情况都把头结点删了，打印的时候begin返回的是随机值，解引用时出错。
		//lt.erase(lt.end()--);
		Print(lt);
		lt.pop_back();
		Print(lt);
		lt.push_front(88);
		Print(lt);
	}
	void test2()
	{
		//struct Point
		//{
		//	int x;
		//	int y;
		//};
		//list<Point> lt;
		//lt.push_back({ 1, 2 });
		//lt.push_back({ 3, 4 });
		//lt.push_back({ 5, 6 });
		//lt.push_back({ 7, 8 });
		//list<Point>::iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	std::cout << (*it).x << ":" << (*it).y << std::endl;    //(*it).x 其实是 当前节点_date->x,*it返回当前节点的_date的引用
		//	std::cout << it->x << ":" << it->y << std::endl;
		//	++it;
		//}
		/*list<Point> lt1;
		lt1 = lt;*/
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		lt1.push_back(1);
		list<int> lt2(lt1.begin(),lt1.end());
		/*list<int> lt2(lt1);
		for (auto e : lt2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;*/

		list<int> lt3;
		std::cout << lt3.empty() << std::endl;
	}
}


int main()
{
	zhy::test2();
	system("pause");
	return 0;
}