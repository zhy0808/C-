#pragma once
#include <deque>

namespace zhy{
	template<class T, class Container=deque<T>>
	class queue
	{
	public:
		queue()
		{

		}
		bool empty() const
		{
			return _queue.empty();
		}
		size_t size() const
		{
			return _queue.size();
		}
		T& front()
		{
			return _queue.front();
		}
		const T& front() const
		{
			return _queue.front();
		}
		T& back()
		{
			return _queue.back();
		}
		const T& back() const
		{
			return _queue.back();
		}
		void push(const T& value)
		{
			_queue.push_back(value);
		}
		void pop()
		{
			_queue.pop_front();
		}


	private:
		Container _queue;
	};
}