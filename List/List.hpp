#pragma once

/*
**==========================
**         Includes
**==========================
*/
#include <cstdlib>
#include "./Node.hpp"
#include "./Iterator.hpp"

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
			~list();
			list<T> &operator=(list<T> &other);

			//Iterators
			iterator				begin(void) { return iterator(this->head); }
			iterator				end(void) { return iterator( this->tail ); }
			reverse_iterator		rbegin(void) { return reverse_iterator( (this->tail && this->tail->_prev) ? this->tail->_prev : NULL ); }
			reverse_iterator		rend(void) { return reverse_iterator( (this->tail && this->tail->_prev) ? this->head->_prev : NULL ); }

			//Capacity
			size_t 					size() const {return (this->_size);}
			bool					empty() const {return ((this->_size == 0) ? true : false);}
			size_t					max_size() const {return (size_t(-1) / (sizeof(list<T>) * (this->_size - (this->_size - 2))));}

			//Element access
			T						front() {return (((this->head) ? this->head->_data : 0 ));}
			T						back() {return (((this->tail && this->tail->_prev) ? this->tail->_prev->_data : 0 ));}

			//Modifiers
			void clear();
			void push_back(T data);
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
**       Capacity
**==========================
*/



/*
**==========================
**     Element access
**==========================
*/



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
void list<T>::push_back(T data)
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

/*
**==========================
**        Operations
**==========================
*/


/*
**==========================
**   Non-member function 
**        overloads
**==========================
*/



} // namespace