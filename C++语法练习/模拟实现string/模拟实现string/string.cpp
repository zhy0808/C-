#include "string.h"
const size_t zhy::string::npos = -1;



zhy::string::string(const char* str)
{
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1];     
	strcpy(_str, str);
}
zhy::string::string(const string& s)
:_str(nullptr) //如果不初始化成nullptr，_str有可能是随机值，交换后temp中是随机值，出作用域时temp会调用析构函数，析构一个随机地址会报错
{
	string temp(s._str);
	swap(temp);
}
zhy::string& zhy::string:: operator=(const string& s)
{
	if (this != &s)                 //防止自己拷贝自己
	{
		string temp(s);
		swap(temp);
	}
	return *this;
}
zhy::string::~string()
{
	if (_str)
	{
		delete[] _str;
		_str = nullptr;
		_capacity = _size = 0;
	}
}





size_t zhy::string::size()
{
	return _size;
}
size_t zhy::string::capacity()
{
	return _capacity;
}
bool zhy::string::empty()
{
	if (_size == 0)
		return true;
	else
		return false;
}
void zhy::string::reserve(size_t capacity)
{
	if (capacity > _capacity) //新开辟的空间比原空间大则增容
	{
		char* str = new char[capacity + 1]; //实际空间要比_capcity大一个，用来放'\0'
		strcpy(str, _str);
		delete[] _str;
		_str = str;
		_capacity = capacity;
	}
}
void zhy::string::resize(size_t n, char c)    //有效字符改成n个，多出的空间用字符c填充
{
	if (n > _size)
	{
		if (n>_capacity)
		{
			reserve(n);
		}
		for (size_t i = _size; i < n; i++)
		{
			_str[i] = c;
		}
	}
	_str[n] = '\0';
	_size = n;
}
void zhy::string::clean()
{
	_size = 0;
	_str[_size] = '\0';
}




char zhy::string:: operator[](size_t i)
{
	assert(i < _size);
	return _str[i];
}
zhy::string::iterator zhy::string::begin()
{
	return _str;
}
zhy::string::iterator zhy::string:: end()
{
	return _str + _size;
}





void zhy::string::push_back(char c)
{
	if (_size == _capacity)
		reserve(2 * _capacity+1);     //如果_size=_capcity=0,开空间就会失败，所以不能用2*_capcity
	_str[_size] = c;
	_size++;
	_str[_size] = '\0';
}
void zhy::string::append(const char* str)
{
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++)
	{
		push_back(str[i]);
	}
}
void zhy::string:: operator+=(char c)
{
	push_back(c);
}
void zhy::string::operator+=(const char* s)
{
	append(s);
}
void zhy::string::operator+=(const string& str)
{
	append(str._str);
}
size_t zhy::string::find(char c, size_t pos)  //从pos位置向后找字符c第一次出现的位置
{
	for (size_t i = pos; i < _size; i++)
	{
		if (_str[i] == c)
			return i;
	}
	return npos;
}
size_t zhy::string::find(const char* s, size_t pos)  //找子串，若有返回子串的起始位置
{
	const char* pch = strstr(_str + pos, s);
	if (pch != nullptr)
	{
		return pch - _str;
	}
	else
		return npos;
}
void zhy::string::insert(size_t pos, char c)       //pos位置插入字符c
{
	assert(pos <= _size);
	if (_size == _capacity)                         //空间满了增容
	{
		reserve(2 * _capacity + 1);
	}
	size_t end = _size + 1;                       //从'\0'开始向后移动
	while (end > pos)                             //将pos及其后面所有字符向后移动
	{
		_str[end] = _str[end - 1];
		end--;
	}
	_str[pos] = c;
	_size++;
}
void zhy::string::insert(size_t pos, char* s)    //pos位置插入字符串s
{
	assert(pos <= _size);
	size_t len = strlen(s);
	if (_size+len > _capacity)           
	{
		reserve(_size + len);
	}
	
	size_t end = _size + len;         
	while (end >= pos + len)
	{
		_str[end] = _str[end - len];          //从'\0'向后移动
		end--;
	}
	strncpy(_str + pos, s, len);
	_size += len;
}
void zhy::string::erase(size_t pos, size_t len)     //从pos位置向后删除len个字符
{
	assert(pos < _size);
	if (len >= _size - pos || len == npos)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		size_t first = pos + len;               //将pos+len后面的字符向前移动
		while (first <= _size)
		{
			_str[first - len] = _str[first];
			first++;
		}
		_size -= len;
	}
}
void zhy::string::swap(string& temp)
{
	_size = strlen(temp._str);
	_capacity = _size;
	std::swap(_str, temp._str); //交换_str,temp._str的空间,_str原有的空间temp出作用域时会释放掉
}
const char* zhy::string::c_str()
{
	return _str;
}









bool zhy::string::operator==(const string& s)
{
	size_t i1 = 0, i2 = 0;
	while (i1 < _size&&i2 < s._size)
	{
		if (_str[i1] != s._str[i2])
			return false;
		else
		{
			i1++;
			i2++;
		}
	}
	if (i1 == _size&&i2 == s._size)
		return true;
	else
		return false;
}
bool zhy::string::operator<(const string& s)
{
	size_t i1 = 0, i2 = 0;
	while (i1 < _size&&i2 < s._size)
	{
		if (_str[i1]>s._str[i2])
			return false;
		else
		{
			i1++;
			i2++;
		}
	}
	if (i1 == _size&&i2 != s._size)
		return true;
	else
		return false;
}
bool zhy::string::operator<=(const string& s)
{
	if (this->operator<(s) || this->operator==(s))
		return true;
	else
		return false;
}
bool zhy::string::operator>(const string& s)
{
	if (this->operator<=(s))
		return false;
	else
		return true;
}
bool zhy::string::operator>=(const string& s)
{
	if (this->operator<(s))
		return false;
	else
		return true;
}
bool zhy::string::operator!=(const string& s)
{
	if (this->operator==(s))
		return false;
	else
		return true;
}





ostream& zhy::operator<<(ostream& out, zhy::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		out << s[i];
	}
	return out;
}
istream& zhy::operator>>(istream& in, zhy::string& s)
{
	s.resize(0);
	char c;
	while (1)
	{
		//in >> c;                //这样输入会导致死循环，空格不能被写进c中，循环无法退出
		in.get(c);
		if (c == ' ' || c == '\n')
		{
			break;
		}
		else
		{
			s.push_back(c);
		}
	}
	return in;
}