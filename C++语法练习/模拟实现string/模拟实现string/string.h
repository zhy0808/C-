#pragma once
#include <assert.h>
#include <iostream>
#include <windows.h>
using namespace std;
#pragma warning (disable:4996)

namespace zhy{
	class string
	{
	public:
		/*string(char* str = "")
			:_str(str),
			 _size(strlen(str)),
			 _capacity(_size)
		{
		}*/
		static const size_t npos;
		typedef char* iterator;
		string(const char* str = "");
		string(const string& s);
		string& operator=(const string& s);
		~string();
		

		size_t size();
		size_t capacity();
		bool empty();
		void reserve(size_t capcity);
		void resize(size_t n, char c = '\0');
		void clean();

		char operator[](size_t i);
		iterator begin();
		iterator end();
		
		void push_back(char c);
		void append(const char* str);
		void operator+=(char c);
		void operator+=(const char* s);
		void operator+=(const string& str);
		size_t find(char c, size_t pos = 0);
		size_t find(const char* s, size_t pos = 0);
		void insert(size_t pos, char c);
		void insert(size_t pos, char* s);
		void erase(size_t pos, size_t len = npos);
		void swap(string& temp);
		const char* c_str();
		
		
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);



	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	ostream& operator<<(ostream& out, zhy::string& s);
	istream& operator>>(istream& in, zhy::string& s);
	
}