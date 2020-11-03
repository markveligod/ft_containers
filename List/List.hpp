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
		typedef Iterator<T> const_iterator;
		typedef Reverse_iterator<T> reverse_iterator;
		typedef Reverse_iterator<T> const_reverse_iterator;

		List();
		List(int count, T data);
		List(iterator first, iterator last);
		List(List const &other);
		List(size_t n, const T &value);
		~List();

		List<T> &operator=(List<T> const &other);

		void push_back(T data);
		void push_front(T data);
		void pop_front();
		void pop_back();
		void clear();
		void insert(iterator index, T data);
		void insert(iterator index, size_t type, T data);
		void insert(iterator index, iterator &first, iterator &last);

		T& front();
		T& back();

		bool empty() const;
		int size() const;
		unsigned long max_size() const;

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
List<T>::List(int count, T data)
{
	this->head = new Node(data);
	this->_size = 1;
	Node *temp_1 = this->head;
	for (int i = 1; i < count; i++)
	{
		Node *temp_2 = new Node(data, NULL, temp_1);
		temp_1->_next = temp_2;
		temp_1 = temp_1->_next;
		this->_size++;
	}
}

template<typename T>
List<T>::List(iterator first, iterator last)
{
	this->head = new Node(first.getIt()->_data);
	this->_size = 1;
	Node *temp_1 = this->head;
	++first;
	while (first != last)
	{
		Node *temp_2 = new Node(first.getIt()->_data, NULL, temp_1);
		temp_1->_next = temp_2;
		temp_1 = temp_1->_next;
		++first;
		this->_size++;
	}
}

template<typename T>
List<T>::List(List const &other)
{
	this->clear();
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
	this->clear();
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

// https://stackoverflow.com/questions/7949486/how-is-max-size-calculated-in-the-function-max-size-in-stdlist
template<typename T>
unsigned long List<T>::max_size() const
{
	return (size_t(-1) / (sizeof(List<T>) * (this->_size - 2)));
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
void List<T>::insert(iterator index, T data)
{
	if (index.getIt() == this->head)
	{
		this->push_front(data);
	}
	else
	{
		Node *prev = this->head;
		while (prev->_next != index.getIt())
			prev = prev->_next;
		Node *temp = new Node(data);
		temp->_next = prev->_next;
		temp->_prev = prev->_next->_prev;
		prev->_next = temp;
		temp->_next->_prev = temp;
		this->_size++;
	}
	
}

template<typename T>
void List<T>::insert(iterator index, size_t type, T data)
{
	if (index.getIt() == this->head)
	{
		for (size_t i = 0; i < type; i++)
			this->push_front(data);
	}
	else
	{
		Node *prev = this->head;
		while (prev->_next != index.getIt())
			prev = prev->_next;
		for (size_t i = 0; i < type; i++)
		{
			Node *temp = new Node(data);
			temp->_next = prev->_next;
			temp->_prev = prev->_next->_prev;
			prev->_next = temp;
			temp->_next->_prev = temp;
			this->_size++;
		}
	}
}

template<typename T>
void List<T>::insert(iterator index, iterator &first, iterator &last)
{
	Node *temp = this->head;
	Node *temp_index = index.getIt();
	if (temp == temp_index)
	{
		Node *temp_end_it = first.getIt();
		while (temp_end_it->_next)
			temp_end_it = temp_end_it->_next;
		while (first != last)
		{
			this->push_front(temp_end_it->_data);
			temp_end_it = temp_end_it->_prev;
			++first;
		}
	}
	else
	{
		while (temp->_next != temp_index)
			temp = temp->_next;
		while (first != last)
		{
			Node *temp_curr = new Node(first.getIt()->_data);
			temp_curr->_next = temp->_next;
			temp->_next->_prev = temp_curr;
			temp_curr->_prev = temp;
			temp->_next = temp_curr;
			temp = temp_curr;
			++first;
			this->_size++;
		}
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

template<typename T>
T& List<T>::front()
{
	return (this->head->_data);
}

template<typename T>
T& List<T>::back()
{
	Node *temp = this->head;
	while (temp->_next)
		temp = temp->_next;
	return (temp->_data);
}

} // namespace