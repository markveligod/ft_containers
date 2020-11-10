#pragma once

/*
**==========================
**         Includes
**==========================
*/
#include <cstdlib>
#include <limits>
#include "./Node.hpp"
#include "./Iterator.hpp"

/**
 * 
 * class list
 * Основной класс листа включает:
 * 
 * main(Constructor, destructor, operator=)
 * iterator(begin end rbegin rend)
 * capacity(size empty max_size)
 * Element access(front back)
 * Modifiers (assign clear insert erase push_back pop_back push_front pop_front resize swap)
 * Operations (merge splice remove (remove_if) reverse unique sort)
 * Non-member function overloads (relational operators (list) swap (list))
 * 
 */

namespace ft
{
	template<typename T>
	class list
	{
		private:
			typedef Node<T> 					Node;

			size_t _size;
			Node *head;
			Node *tail;
		public:
			typedef Iterator<T> 				iterator;
			typedef Reverse_iterator<T> 		reverse_iterator;

			//main
			list();
			list(size_t count, T data);
			list(iterator &first, iterator &last);
			list(list<T> &other);
			virtual ~list();
			list<T> &operator=(list<T> &other);

			//Iterators
			iterator				begin(void) { return iterator(this->head); }
			iterator				end(void) { return iterator( this->tail ); }
			reverse_iterator		rbegin(void) { return reverse_iterator( (this->tail && this->tail->_prev) ? this->tail->_prev : NULL ); }
			reverse_iterator		rend(void) { return reverse_iterator( (this->tail && this->tail->_prev) ? this->head->_prev : NULL ); }

			//Capacity
			size_t 					size() const {return (this->_size);}
			bool					empty() const {return ((this->_size == 0) ? true : false);}
			size_t					max_size() const {return ((std::numeric_limits<size_t>::max() / (sizeof(Node))) / 2);}

			//Element access
			T						front() {return (((this->head) ? this->head->_data : 0 ));}
			T						back() {return (((this->tail && this->tail->_prev) ? this->tail->_prev->_data : 0 ));}

			//Modifiers
			void clear();
			void push_back(const T &data);
			void pop_back();
			void push_front(const T &data);
			void pop_front();
			void resize(size_t n, T data = T());
			void assign(iterator first, iterator last);
			void assign(size_t n, const T &data);
			iterator insert(iterator position, const T& data);
			void insert(iterator position, size_t n, const T& data);
			void insert(iterator position, iterator first, iterator last);
    		iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap(list &other);

			//Operations:
			void splice(iterator position, list &other);
			void splice(iterator position, list &other, iterator i);
			void splice(iterator position, list &other, iterator first, iterator last);
			void remove(const T &data);
			bool binarypredicate(const T &i, const T &j) {return (i == j);}
			void unique();
			bool compare(const T &i, const T &j) {return (i < j);}
			void merge(list &other);
			void sort();
			void reverse();

			template <class Compare>
  			void sort(Compare comp)
			{
				iterator begin_1 = this->begin();
				iterator begin_2 = this->begin();
				iterator end = this->end();
				T temp;

				while (++begin_2 != end)
				{
					if (comp(begin_2.getNode()->_data, begin_1.getNode()->_data))
					{
						temp = begin_1.getNode()->_data;
						begin_1.getNode()->_data = begin_2.getNode()->_data;
						begin_2.getNode()->_data = temp;
						begin_1 = this->begin();
						begin_2 = this->begin();
					}
					else
						++begin_1;
				}
			}

			template <class Compare>
			void merge (list &other, Compare comp)
			{
				iterator begin_this = this->begin();
				iterator end_this = this->end();
				iterator begin_other = other.begin();
				iterator end_other = other.end();
				iterator temp;

				while (begin_other != end_other)
				{
					if (comp(begin_this.getNode()->_data, begin_other.getNode()->_data))
					{
						temp = begin_other;
						++begin_other;
						this->splice(begin_this, other, temp);
						if (begin_this != end_this)
							++begin_this;
					}
					else
						if (begin_this != end_this)
							++begin_this;
				}
			}

			template <class BinaryPredicate>
  			void unique(BinaryPredicate binary_pred)
			{
				ft::list<T>::iterator begin = this->begin();
				ft::list<T>::iterator end = this->end();
				ft::list<T>::iterator pos;
				while (begin != end)
				{
					if ((begin.getNode()->_next != this->tail) && binary_pred(begin.getNode()->_data, begin.getNode()->_next->_data))
					{
						pos = begin;
						++begin;
						this->erase(pos);
					}
					else
					{
						++begin;	
					}
				}
			}
			
			template <class Predicate>
  			void remove_if (Predicate pred)
			{
				iterator begin = this->begin();
				iterator end = this->end();
				iterator temp;

				while (begin != end)
				{
					if (pred(begin.getNode()->_data))
					{
						temp = begin;
						++begin;
						this->erase(temp);
					}
					else
					{
						++begin;
					}		
				}
			}
	};

/*
**==========================
**       Constructor
**       Destructor
**       operator=
**==========================
*/

template<typename T>
list<T>::list()
{
	this->_size = 0;
	this->head = NULL;
	this->tail = NULL;
}

template<typename T>
list<T>::list(size_t count, T data)
{
	if (count > 0)
	{
		this->head = new Node(data);
		this->_size = 1;
		Node *temp_1 = this->head;
		Node *temp_2;
		for (size_t i = 1; i < count; i++)
		{
			temp_2 = new Node(data, NULL, temp_1);
			temp_1->_next = temp_2;
			temp_1 = temp_1->_next;
			this->_size++;
		}
		this->tail = new Node;
		temp_2->_next = this->tail;
		this->tail->_next = this->head;
		this->tail->_prev = temp_2;
		this->head->_prev = this->tail;
	}
}

template<typename T>
list<T>::list(iterator &first, iterator &last)
{
	this->head = new Node(first.getNode()->_data);
	this->_size = 1;
	Node *temp_1 = this->head;
	Node *temp_2;
	while (++first != last)
	{
		temp_2 = new Node(first.getNode()->_data, NULL, temp_1);
		temp_1->_next = temp_2;
		temp_1 = temp_1->_next;
		this->_size++;
	}
	this->tail = new Node;
	temp_2->_next = this->tail;
	this->tail->_next = this->head;
	this->tail->_prev = temp_2;
	this->head->_prev = this->tail;
}

template<typename T>
list<T>::list(list<T> &other)
{
	this->_size = 0;
	this->head = NULL;
	this->tail = NULL;
	*this = other;
}

template<typename T>
list<T>::~list()
{
	this->clear();
}

template<typename T>
list<T> &list<T>::operator=(list<T> &other)
{
	if (!this->empty())
		this->clear();
	for (iterator dd = other.begin(); dd != other.end(); ++dd)
		this->push_back(dd.getNode()->_data);
	this->_size = other._size;
	return(*this);
}

/*
**==========================
**        Modifiers
**==========================
*/

template<typename T>
void list<T>::clear()
{
	if (this->head)
		while (this->head != this->tail)
		{
			Node *temp = this->head->_next;
			delete this->head;
			this->head = temp;
		}
	if (this->tail)
		delete this->tail;
	this->_size = 0;
	this->head = NULL;
	this->tail = NULL;
}

template<typename T>
void list<T>::assign(iterator first, iterator last)
{
	this->clear();
	while (first != last)
	{
		this->push_back(first.getNode()->_data);
		++first;
	}
}

template<typename T>
void list<T>::assign(size_t n, const T &data)
{
	this->clear();
	for (size_t i = 0; i < n; i++)
		this->push_back(data);
}

template<typename T>
void list<T>::pop_back()
{
	Node *temp = this->tail->_prev;
	temp->_prev->_next = this->tail;
	this->tail->_prev = temp->_prev;
	delete temp;
	this->_size--;
}

template<typename T>
void list<T>::push_back(const T &data)
{
	if (!this->tail)
		this->tail = new Node;
	if (this->head == NULL)
	{
		this->head = new Node(data, this->tail);
		this->head->_prev = this->tail;
		this->tail->_next = this->head;
		this->tail->_prev = this->head;
		
	}
	else
	{
		Node *curr = this->head;
		while (curr->_next != this->tail)
			curr = curr->_next;
		Node *temp = new Node(data);
		curr->_next = temp;
		temp->_prev = curr;
		temp->_next = this->tail;
		this->tail->_prev = temp;
	}
	this->_size++;
}

template<typename T>
void list<T>::push_front(const T &data)
{
	if (!this->tail)
		this->tail = new Node;
	if (this->head == NULL)
	{
		this->head = new Node(data, this->tail);
		this->head->_prev = this->tail;
		this->tail->_next = this->head;
		this->tail->_prev = this->head;
		
	}
	else
	{
		Node *curr = this->head;
		this->head = new Node(data);
		this->head->_next = curr;
		this->head->_prev = this->tail;
		this->tail->_next = this->head;
		curr->_prev = this->head;
		
	}
	this->_size++;
}

template<typename T>
void list<T>::pop_front()
{
	Node *temp = this->head;
	this->head = this->head->_next;
	this->tail->_next = this->head;
	this->head->_prev = this->tail;
	delete temp;
	this->_size--;
}

template<typename T>
void list<T>::resize(size_t n, T data)
{
	if (this->_size < n)
	{
		while (this->_size < n)
			this->push_back(data);	
	}
	else
	{
		while (this->_size > n)
			this->pop_back();
	}
}

template<typename T>
typename list<T>::iterator list<T>::insert(iterator position, const T& data)
{
	Node *pos = position.getNode();
	if (pos == this->head)
		this->push_front(data);
	else if (pos == this->tail)
		this->push_back(data);
	else
	{
		Node *temp = this->head;
		while (temp->_next != pos)
			temp = temp->_next;
		Node *new_node = new Node(data);
		temp->_next = new_node;
		pos->_prev = new_node;
		new_node->_prev = temp;
		new_node->_next = pos;
		this->_size++;
	}
	return (iterator(this->head));
}

template<typename T>
void list<T>::insert(iterator position, size_t n, const T& data)
{
	Node *pos = position.getNode();
	if (pos == this->head)
	{
		for (size_t i = 0; i < n; i++)
			this->push_front(data);
		
	}
	else if (pos == this->tail)
	{
		for (size_t i = 0; i < n; i++)
			this->push_back(data);
	}
	else
	{
		Node *temp = this->head;
		while (temp->_next != pos)
			temp = temp->_next;
		for (size_t i = 0; i < n; i++)
		{
			Node *new_node = new Node(data);
			temp->_next = new_node;
			pos->_prev = new_node;
			new_node->_prev = temp;
			new_node->_next = pos;
			this->_size++;
			temp = temp->_next;
		}
	}
}

template<typename T>
void list<T>::insert(iterator position, iterator first, iterator last)
{
	Node *pos = position.getNode();
			
	if (pos == this->head)
	{
		--last;
		--first;
		while (last != first)
		{
			push_front(last.getNode()->_data);
			--last;
		}
	}
	else if (pos == this->tail)
	{
		while (first != last)
		{
			push_back(first.getNode()->_data);
			++first;
		}
	}
	else
	{
		Node *temp = this->head;
		while (temp->_next != pos)
			temp = temp->_next;
		while (first != last)
		{
			Node *new_node = new Node(first.getNode()->_data);
			temp->_next = new_node;
			pos->_prev = new_node;
			new_node->_prev = temp;
			new_node->_next = pos;
			temp = temp->_next;
			this->_size++;
			++first;
		}	
	}				
}

template<typename T>
typename list<T>::iterator list<T>::erase(iterator position)
{
	Node *pos = position.getNode();
	if (pos == this->head)
		this->pop_front();
	else if (pos == this->tail)
		this->pop_back();
	else
	{
		Node *temp = this->head;
		while (temp->_next != pos)
			temp = temp->_next;
		temp->_next = pos->_next;
		pos->_next->_prev = temp;
		delete pos;
		this->_size--;
	}
	return (iterator(this->head));
}

template<typename T>
typename list<T>::iterator list<T>::erase(iterator first, iterator last)
{
	Node *begin = first.getNode();
	Node *end = last.getNode();

	if (begin == this->head)
	{
		while (first != last)
		{
			++first;
			this->pop_front();
		}
	}
	else if (end == this->tail)
	{
		--last;
		while (first != last)
		{
			--last;
			this->pop_back();
		}
		this->pop_back();
	}
	else
	{
		begin->_prev->_next = end;
		end->_prev = begin->_prev;
		Node *temp;
		while (first != last)
		{
			temp = first.getNode();
			++first;
			delete temp;
			this->_size--;
		}
	}
	return (iterator(this->head));
}

template<typename T>
void list<T>::swap(list<T> &other)
{
	list<T> temp = *this;
	*this = other;
	other = temp;
}

/*
**==========================
**        Operations
**==========================
*/

template<typename T>
void list<T>::splice(iterator position, list<T> &other)
{
	this->insert(position, other.begin(), other.end());
	other.clear();
}

template<typename T>
void list<T>::splice(iterator position, list<T> &other, iterator i)
{
	this->insert(position, i.getNode()->_data);
	other.erase(i);
}

template<typename T>
void list<T>::splice(iterator position, list<T> &other, iterator first, iterator last)
{
	this->insert(position, first, last);
	other.erase(first, last);
}

template<typename T>
void list<T>::remove(const T &data)
{
	ft::list<T>::iterator begin = this->begin();
	ft::list<T>::iterator end = this->end();
	ft::list<T>::iterator pos;
	while (begin != end)
	{
		if (begin.getNode()->_data == data)
		{
			pos = begin;
			++begin;
			this->erase(pos);
		}
		else
		{
			++begin;	
		}
	}
}

template<typename T>
void list<T>::unique()
{
	ft::list<T>::iterator begin = this->begin();
	ft::list<T>::iterator end = this->end();
	ft::list<T>::iterator pos;
	while (begin != end)
	{
		if ((begin.getNode()->_next != this->tail) && binarypredicate(begin.getNode()->_data, begin.getNode()->_next->_data))
		{
			pos = begin;
			++begin;
			this->erase(pos);
		}
		else
		{
			++begin;	
		}
	}
}

template<typename T>
void list<T>::merge(list<T> &other)
{
	iterator begin_this = this->begin();
	iterator end_this = this->end();
	iterator begin_other = other.begin();
	iterator end_other = other.end();
	iterator temp;

	while (begin_other != end_other)
	{
		if (compare(begin_other.getNode()->_data, begin_this.getNode()->_data) || begin_this == end_this)
		{
			temp = begin_other;
			++begin_other;
			this->splice(begin_this, other, temp);
		}
		else
			++begin_this;
	}
}

template<typename T>
void list<T>::sort()
{
	iterator begin_1 = this->begin();
	iterator begin_2 = this->begin();
	iterator end = this->end();
	T temp;

	while (++begin_2 != end)
	{
		if (compare(begin_2.getNode()->_data, begin_1.getNode()->_data))
		{
			temp = begin_1.getNode()->_data;
			begin_1.getNode()->_data = begin_2.getNode()->_data;
			begin_2.getNode()->_data = temp;
			begin_1 = this->begin();
			begin_2 = this->begin();
		}
		else
			++begin_1;
	}
}

template<typename T>
void list<T>::reverse()
{
	list<T> temp;
	iterator begin = this->begin();
	iterator end = this->end();

	while (begin != end)
	{
		temp.push_front(begin.getNode()->_data);
		++begin;
	}
	this->clear();
	*this = temp;
}

/*
**==========================
**   Non-member function 
**        overloads
**==========================
*/

template<typename T>
bool operator==(list<T> &lhs, list<T> &rhs)
{
	ft::list<int>::iterator begin_lhs = lhs.begin();
	ft::list<int>::iterator end_lhs = lhs.end();
	ft::list<int>::iterator begin_rhs = rhs.begin();
	ft::list<int>::iterator end_rhs = rhs.end();

	while ((begin_lhs != end_lhs) && (begin_rhs != end_rhs))
	{
		if (begin_rhs.getNode()->_data != begin_lhs.getNode()->_data)
			return (false);
		++begin_lhs;
		++begin_rhs;
	}
	if ((begin_lhs != end_lhs) || (begin_rhs != end_rhs))
		return (false);
	return (true);
}


template<typename T>
bool operator!=(list<T> &lhs, list<T> &rhs)
{
	if (lhs == rhs)
		return (false);
	return (true);
}

template<typename T>
bool operator<(list<T> &lhs, list<T> &rhs)
{
	if (lhs.size() < rhs.size())
		return (true);
	if (lhs.size() > rhs.size())
		return (false);
	
	ft::list<int>::iterator begin_lhs = lhs.begin();
	ft::list<int>::iterator end_lhs = lhs.end();
	ft::list<int>::iterator begin_rhs = rhs.begin();
	ft::list<int>::iterator end_rhs = rhs.end();

	while ((begin_lhs != end_lhs) && (begin_rhs != end_rhs) && (begin_lhs.getNode()->_data == begin_rhs.getNode()->_data))
	{
		++begin_rhs;
		++begin_lhs;
	}
	if (begin_lhs.getNode()->_data >= begin_rhs.getNode()->_data)
		return (false);
	return (true);
}

template<typename T>
bool operator<=(list<T> &lhs, list<T> &rhs)
{
	if (lhs < rhs || lhs == rhs)
		return (true);
	return (false);
}

template<typename T>
bool operator>(list<T> &lhs, list<T> &rhs)
{
	if (lhs.size() < rhs.size())
		return (false);
	if (lhs.size() > rhs.size())
		return (true);
	
	ft::list<int>::iterator begin_lhs = lhs.begin();
	ft::list<int>::iterator end_lhs = lhs.end();
	ft::list<int>::iterator begin_rhs = rhs.begin();
	ft::list<int>::iterator end_rhs = rhs.end();

	while ((begin_lhs != end_lhs) && (begin_rhs != end_rhs) && (begin_lhs.getNode()->_data == begin_rhs.getNode()->_data))
	{
		++begin_rhs;
		++begin_lhs;
	}
	if (begin_lhs.getNode()->_data <= begin_rhs.getNode()->_data)
		return (false);
	return (true);
}

template<typename T>
bool operator>=(list<T> &lhs, list<T> &rhs)
{
	if (lhs > rhs || lhs == rhs)
		return (true);
	return (false);
}

template<typename T>
void swap(list<T> &x, list<T> &y)
{
	list<T> temp = x;
	x = y;
	y = temp;
}


} // namespace