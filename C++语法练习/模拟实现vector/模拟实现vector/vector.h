#pragma once
#include <assert.h>

namespace zhy{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
		}
		vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n);
			while (n)
			{
				push_back(value);
				n--;
			}
		}
		template<class Iterator>                         //用任意容器的迭代器来初始化vector
		vector(Iterator first, Iterator last)
		{
			reserve(last - first);
			while (first<last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)                      //拷贝构造
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			iterator begin = _start;
			const_iterator it = v.cbegin();
			while (it < v.cend())
			{
				*begin = *it;
				begin++;
				it++;
			}
			_finish = _start + v.size();
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T* temp = new T[n];
				if (_start)
				{
					//memcpy(temp, _start, sizeof(*T)*size());   memcpy是二进制格式拷贝，是将一段内存空间中的内容直接拷贝到
					//目标空间中（浅拷贝），对涉及到内存资源管理的自定义类型就会出错，只能用来拷贝内置类型。
					//例：原空间中存放的是string类型的数据，用memcpy拷贝时，只使新空间指向了旧的string对象，当旧空间释放后，新空间
					//中就都是野指针。
					for (size_t i = 0; i < size(); i++)         //借用了自定义类型的  operator=  来完成深拷贝
					{
						temp[i] = _start[i];           
					}
				}
				delete[] _start;
				_start = temp;
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t x, const T& value = T())
		{
			if (x > capacity())
			{
				reserve(x);
			}
			if (x <= size())
			{
				_finish = _start + x;
			}
			else
			{
				iterator begin = _finish;
				_finish = _start + x;
				while (begin != _finish)
				{
					*begin = value;
					begin++;
				}
			}
		}
		void push_back(const T& value)
		{
			insert(end(), value);
		}
		void pop_back()
		{
			erase(--end());
		}
		iterator insert(iterator pos,const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t p = pos - _start;
				reserve(capacity() * 2 + 1);   //+1是为了防止capacity为0，增容失败
				pos = _start + p;
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			_finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			iterator i = pos + 1;
			while (i < _finish)
			{
				*(i - 1) = *i;
				i++;
			}
			_finish--;
			return pos;
		}
		void swap(vector<T>& temp)
		{
			std::swap(_start, temp._start);
			std::swap(_finish, temp._finish);
			std::swap(_endofstorage, temp._endofstorage);
		}
		const_iterator cbegin() const          //const对象调用
		{
			return _start;
		}
		const_iterator cend() const
		{
			return _finish;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		size_t capacity() const                     //加const的原因：const对象和非const对象都可以调用
		{
			return _endofstorage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		bool empty()
		{
			if (size() == 0)
				return true;
			else
				return false;
		}
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		const T& operator[](size_t n) const
		{
			assert(n < size());
			return _start[n];
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

	private:
		iterator _start;              //指向vector有效数据的开始
		iterator _finish;             //指向vector有效数据的结尾的下一个位置
		iterator _endofstorage;       //指向vector实际占有内存的尾
	};
}
