#pragma once
#include <deque>

namespace zhy{
	template<class T, class Container=deque<T>>
	class stack
	{
	public:
		stack()
		{

		}
		bool empty() const
		{
			return _stack.empty();
		}
		size_t size() const
		{
			return _stack.size();
		}
		T& top()
		{
			return _stack.back();
		}
		const T& top() const
		{
			return _stack.back();
		}
		void push(const T& value)
		{
			_stack.push_back(value);
		}
		void pop()
		{
			_stack.pop_back();
		}
	private:
		Container _stack;
	};
}