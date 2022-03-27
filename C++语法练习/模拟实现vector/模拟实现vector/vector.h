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
		template<class Iterator>                         //�����������ĵ���������ʼ��vector
		vector(Iterator first, Iterator last)
		{
			reserve(last - first);
			while (first<last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)                      //��������
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
					//memcpy(temp, _start, sizeof(*T)*size());   memcpy�Ƕ����Ƹ�ʽ�������ǽ�һ���ڴ�ռ��е�����ֱ�ӿ�����
					//Ŀ��ռ��У�ǳ�����������漰���ڴ���Դ������Զ������;ͻ����ֻ�����������������͡�
					//����ԭ�ռ��д�ŵ���string���͵����ݣ���memcpy����ʱ��ֻʹ�¿ռ�ָ���˾ɵ�string���󣬵��ɿռ��ͷź��¿ռ�
					//�оͶ���Ұָ�롣
					for (size_t i = 0; i < size(); i++)         //�������Զ������͵�  operator=  ��������
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
				reserve(capacity() * 2 + 1);   //+1��Ϊ�˷�ֹcapacityΪ0������ʧ��
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
		const_iterator cbegin() const          //const�������
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
		size_t capacity() const                     //��const��ԭ��const����ͷ�const���󶼿��Ե���
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
		iterator _start;              //ָ��vector��Ч���ݵĿ�ʼ
		iterator _finish;             //ָ��vector��Ч���ݵĽ�β����һ��λ��
		iterator _endofstorage;       //ָ��vectorʵ��ռ���ڴ��β
	};
}
