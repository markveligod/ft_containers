#pragma once

#include <cstdlib>
#include "./Node.hpp"
#include "./Iterator.hpp"

namespace ft
{

template<typename T>
class List
{
	private:
		typedef Node<T> Node;

		int _size;
		Node *head;

	public:
		typedef Iterator<T> iterator;
		typedef Const_iterator<T> const_iterator;
		typedef Reverse_iterator<T> reverse_iterator;
		typedef Const_reverse_iterator<T> const_reverse_iterator;

		List();
		List(List const &other);
		~List();

		List<T> &operator=(List<T> const &other);

		void push_back(T data);
		void push_front(T data);
		void pop_front();
		void pop_back();
		void clear();
		void insert(T data, int index);

		bool empty() const;
		int size() const;
		int max_size() const;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};


template<typename T>
List<T>::List()
{
	this->_size = 0;
	this->head = NULL;
}

template<typename T>
List<T>::List(List const &other)
{
	*this = other;
}

template<typename T>
List<T>::~List()
{
	this->clear();
}

template<typename T>
List<T> &List<T>::operator=(List<T> const &other)
{
	*this = other;
	return(*this);
}

template<typename T>
int List<T>::size() const
{
	return (this->_size);
}

template<typename T>
bool List<T>::empty() const
{
	if (this->head)
		return (false);
	return (true);
}

template<typename T>
int List<T>::max_size() const
{
	return (this->_size);
}

template<typename T>
void List<T>::push_back(T data)
{
	if (this->head == NULL)
	{
		head = new Node(data);
	}
	else
	{
		Node *curr = this->head;
		while (curr->_next != NULL)
			curr = curr->_next;
		curr->_next = new Node(data);
		curr->_next->_prev = curr;
	}
	this->_size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node(data, head);
	head->_next->_prev = head;
	this->_size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node *temp = this->head;
	this->head = this->head->_next;
	delete temp;
	this->head->_prev = NULL;
	this->_size--;
}

template<typename T>
void List<T>::pop_back()
{
	Node *temp = this->head;
	Node *temp_2;
	while (temp->_next)
	{
		if (temp->_next && temp->_next->_next == NULL)
			temp_2 = temp;
		temp = temp->_next;
	}
	temp->_prev = NULL;
	delete temp;
	temp_2->_next = NULL;
	this->_size--;
}

template<typename T>
void List<T>::clear()
{
	while (this->head)
	{
		Node *temp = this->head->_next;
		delete this->head;
		this->head = temp;
	}
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		this->push_front(data);
	}
	else
	{
		Node *prev = this->head;
		for (int i = 0; i < index - 1; i++)
			prev = prev->_next;
		Node *curr = new Node(data, prev->_next);
		prev->_next->_prev = curr;
		prev->_next = curr;
		curr->_prev = prev;
		this->_size++;
	}
	
}

template<typename T>
typename List<T>::iterator List<T>::begin()
{
	return (List<T>::iterator(this->head));
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
	List<T>::Node *temp = this->head;
	while (temp->_next)
		temp = temp->_next;
	return (List<T>::iterator(temp->_next));
}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
	return (List<T>::const_iterator(this->head));
}

template<typename T>
typename List<T>::const_iterator List<T>::end() const
{
	List<T>::Node *temp = this->head;
	while (temp->_next)
		temp = temp->_next;
	return (List<T>::const_iterator(temp->_next));
}

template<typename T>
typename List<T>::reverse_iterator List<T>::rbegin()
{
	List<T>::Node *temp = this->head;
	while (temp->_next)
		temp = temp->_next;
	return (List<T>::reverse_iterator(temp));
}

template<typename T>
typename List<T>::reverse_iterator List<T>::rend()
{
	return (List<T>::reverse_iterator(this->head->_prev));
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::rbegin() const
{
	List<T>::Node *temp = this->head;
	while (temp->_next)
		temp = temp->_next;
	return (List<T>::const_reverse_iterator(temp));
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::rend() const
{
	return (List<T>::const_reverse_iterator(this->head->_prev));
}

} // namespace