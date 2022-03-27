#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "vector.h"
void test1()
{
	
	zhy::vector<int> v(10, 3);
	v.push_back(77);
	zhy::vector<int>::iterator it = v.begin() + 4;

	v.erase(it);
	std::cout << v[v.size()-1] << std::endl;
	zhy::vector<int> v1(v);
	for (size_t i = 0; i < v1.size();i++)
	{
		std::cout << v1[i] << std::endl;
	}
	zhy::vector<std::string> s(5, "asd");
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	zhy::vector<int> v2;
	v2 = v1;
	for (auto e : v2)
	{
		std::cout << e;
	}
	std::cout << std::endl;
	v2.resize(10,9);
	for (auto e : v2)
	{
		std::cout << e <<" ";
	}
	std::cout << std::endl;

}

void test2()
{
	int ar[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);
	std::vector<int> v(ar, ar + n);
	std::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it != 0)
			std::cout << *it;
		else
			it = v.erase(it);
			//v.erase(it);        //erase�󲻸�����������ֵ���������ͻ�ʧЧ
		it++;
	}
}

void test3()
{
	std::string s("hello world!");
	zhy::vector<char> c(s.begin(), s.end());
	for (auto e : c)
	{
		std::cout << e;
	}
	std::cout << std::endl;
}
void test4()
{
	std::vector<int> v(4, 2);
	std::vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it++ *= 2;
	}
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << v.empty() << std::endl;
	
}
void test5()
{
	std::vector<int> v(6, 7);
	v.resize(3);              //���ռ���С��3
	v.resize(10, 8);          //���ռ�����Ϊ10������Ŀռ���8���
	v.resize(15);             //���ռ�����15
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
template<class T>
void Print(const std::vector<T>& v)
{
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
void test6()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	Print(v);
	v.insert(v.begin() + 2, 88);
	Print(v);
	v.pop_back();
	Print(v);
	v.erase(v.begin() + 1);
	Print(v);
	std::vector<int> v1(8 , 1);
	v.swap(v1);
	Print(v);
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] = 2;
	}
	Print(v);
}

void test7()
{
	std::vector<int> v(5, 1);
	auto it = v.begin();
	v.resize(100, 2);    //�ڲ����ݺ�v�¿�����һ��ռ䣬it��ָ���ԭ���Ŀռ䣬���µ�����ʧЧ
	v.reserve(100);      //�����ڼ���ܻ�����ײ������ı�,ԭ�ռ��ͷţ�������ʧЧ
	v.insert(v.begin(), 1);  //��������������ݣ�ԭ�ռ��ͷţ�������ʧЧ
	v.push_back(8);	

}
int main()
{
	test7();
	system("pause");
	return 0;
}