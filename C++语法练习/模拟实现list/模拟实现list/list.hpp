#include <iostream>

namespace zhy
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* _next;        //ָ��ǰ���ڵ�
		__list_node<T>* _prev;        //ָ���̽ڵ�
		T _date;                      //�������
		__list_node(const T& value=T())  //��ʼ���ڵ�
			:_date(value)
			, _next(nullptr)
			, _prev(nullptr)
		{
		}
	};
	template<class T,class Ref,class Ptr>    //��������ģ�������������������ǿɶ���д�Ļ���ֻ����
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;  //����ʵ�ʴ���ĵ������������ɶ�Ӧ���͵ĵ�����
		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{
		}
		//�������졢��ֵ��������ء��������ñ�����Ĭ�����ɵġ���Ϊ����������Щ��Ϊ����ǳ����
		bool operator==(const self& x) const
		{
			return _node == x._node;
		}
		bool operator!=(const self& x) const
		{
			return _node != x._node;
		}
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)           //���ܷ������ã���Ϊ���ص��Ǿֲ�����������������ͻᱻ�ͷ�
		{
			self temp = *this;
			++(*this);
			return temp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self temp = *this;
			--(*this);
			return temp;
		}
		Ref operator*() const    //�����������const���ͣ���Ref����const T&���ⲿ�����޸�
		{
			return _node->_date;    
		}
		Ptr operator->() const   //���ص�ǰ�ڵ�_date���ֵĵ�ַ�����ⲿ��ָ��ķ�ʽ��ʹ��
		{
			return &_node->_date;
		}


	};


	template<class T>   
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;   //�������ξʹ����ǿɶ���д�ĵ���������iterator�ǿɶ���д������
		typedef __list_iterator<T, const T&, const T*> const_iterator; //�������ξʹ�����ֻ������������const_iterator��ֻ��������
		list()
		{
			_head = new node();     //����һ��ͷ���
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& lt)
		{
			_head = new node();
			_head->_next = _head;
			_head->_prev = _head;
			const_iterator it = lt.begin();
			while (it != lt.end())
			{
				push_back(*it);
				++it;
			}
		}
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new node();                        //���ﲻ��дnode _head = new node();   �´���������_node�Ǹ��ֲ���������û��Ϊ��Ա������ʼ��
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				std::cout << *first << std::endl;
				push_back(*first);
				++first;
			}
		}


		//�ִ�д��
		//list(const list<T>& lt)
		//{
		//	node* _head = new node();               //����ҲҪ��ʼ��һ��ͷ�ڵ㣬���򽻻�֮��temp�õ�����һ��û�г�ʼ����ͷ��㣬������������ʱ�ͻ����
		//	_head->_next = _head;
		//	_head->_prev = _head;
		//	list<T> temp(lt.begin(), lt.end());
		//	std::swap(_head, temp._head);
		//}




		list<T> operator=(list<T> lt)
		{
			std::swap(_head, lt._head);
			return *this;
		}

		~list()
		{
			clean();
			delete _head;
			_head = nullptr;
		}
		void clean()
		{
			iterator it = (*this).begin();
			while (it != (*this).end())
			{
				it = erase(it);                       //erase���������ʧЧ��Ҫ�����������¸�ֵ    
				//erase(it++);  ������ͬ��
			}
		}
		bool empty()
		{
			return begin() == end();
		}
		iterator begin() 
		{
			return _head->_next;   //iterator b(_head->next);   return b;
		}
		iterator end()
		{
			return _head;          //iterator b(_head);   return b;
		}
		const_iterator begin() const   //const���ε���thisָ�룬��ʾ���øú����Ķ����Ǳ�const���ε�
		{
			return _head->_next;   //iterator b(_head->next);   return b;
		}
		const_iterator end() const
		{
			return _head;          //iterator b(_head);   return b;
		}
		void push_back(const T& value)
		{
			node* tail = _head->_prev;
			node* newnode = new node(value);
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
			//insert(end(), value);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		iterator insert(iterator pos, const T& x)
		{
			node* newnode = new node(x);
			node* cur = pos._node;
			node* prev = cur->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			iterator ret(newnode);
			return ret;
		}
		void pop_back()
		{
			erase(begin());
		}
		void pop_front()
		{
			erase(--end());
		}
		iterator erase(iterator pos)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;              //��Ҫɾ���Ŀռ��ͷŵ�����ֹ�ڴ�й©
			iterator ret(next);      //������λ�õĵ�����
			return ret;
		}
	private:
		node* _head;
	};
}

