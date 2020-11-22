#pragma once

#include "../../main.hpp"
#include "Node.hpp"
#include "Iterator.hpp"

namespace ft 
{
	template < typename T, typename Alloc = std::allocator<T> >
	class list 
	{
		public:
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef T&														  	reference;
			typedef const T&													const_reference;
			typedef T*														  	pointer;
			typedef const T*													const_pointer;
			typedef node<T>*													node_pointer;
			typedef ptrdiff_t												   	difference_type;
			typedef size_t													  	size_type;
			typedef Iterator<value_type, pointer, reference>					iterator;
			typedef Iterator<value_type, const_pointer, const_reference>		const_iterator;
			typedef RevIterator<value_type, pointer, reference>				 	reverse_iterator;
			typedef RevIterator<value_type, const_pointer, const_reference>	 	const_reverse_iterator;

		private:
			node_pointer	head;
			node_pointer	tail;
			allocator_type	alloc;
			size_type		len_size;

			void init_default_param(const allocator_type& alloc)
			{
				this->alloc = alloc;
				this->len_size = 0;
				this->head = new node<T>();
				this->tail = new node<T>();
				this->head->next = this->tail;
				this->tail->prev = this->head;
			}

		public:
			//Main
			explicit list(const allocator_type& alloc = allocator_type());
			explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			explicit list(iterator first, iterator last, const allocator_type& alloc = allocator_type());
			explicit list(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type());
			list(const list &other);
			list<T, Alloc> &operator=(const list<T, Alloc> &other);
			~list();
		
			// Iterators
			iterator				begin() { return iterator(this->head->next);}
			const_iterator			begin() const { return const_iterator(this->head->next);}
			iterator				end() { return iterator(this->tail);}
			const_iterator			end() const { return const_iterator(this->tail);}
			reverse_iterator		rbegin() { return reverse_iterator(this->tail->prev);}
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(this->tail->prev);}
			reverse_iterator		rend() { return reverse_iterator(this->head);}
			const_reverse_iterator	rend() const { return const_reverse_iterator(this->head);}
			
			//Capacity
			// https://stackoverflow.com/questions/7949486
			bool					empty() const { return (this->len_size == 0);}
			size_type				size() const { return this->len_size;}
			size_type				max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(node<value_type>)));}

			//Element access
			reference				front() { return this->head->next->data;}
			const_reference			front() const { return this->head->next->data;}
			reference				back() { return this->tail->prev->data;}
			const_reference			back() const { return this->tail->prev->data;}

			//Modifiers
			void 					assign(iterator first, iterator last);
			void 					assign(const_iterator first, const_iterator last);
			void 					assign(size_type n, const value_type& val);
			void					push_back(const value_type &val);
			void					pop_back();
			void					clear();
				

	};

/*
**==========================
**          Main
**==========================
*/

template < typename T, typename Alloc >
list<T, Alloc>::list(const allocator_type& alloc)
{
	this->init_default_param(alloc);
}

template < typename T, typename Alloc >
list<T, Alloc>::list(size_type n, const value_type& val, const allocator_type& alloc)
{
	this->init_default_param(alloc);
	this->assign(n, val);
}

template < typename T, typename Alloc >
list<T, Alloc>::list(iterator first, iterator last, const allocator_type& alloc)
{
	this->init_default_param(alloc);
	this->assign(first, last);
}

template < typename T, typename Alloc >
list<T, Alloc>::list(const_iterator first, const_iterator last, const allocator_type& alloc)
{
	this->init_default_param(alloc);
	this->assign(first, last);
}

template < typename T, typename Alloc >
list<T, Alloc>::list(const list &other)
{
	*this = other;
}

template < typename T, typename Alloc >
list<T, Alloc> &list<T, Alloc>::operator=(const list<T, Alloc> &other)
{
	this->clear();
	this->head->next = this->tail;
	this->tail->prev = this->head;
	this->len_size = 0;
	this->assign(other.begin(), other.end());
	return (*this);
}

template < typename T, typename Alloc >
list<T, Alloc>::~list()
{
	this->clear();
	delete this->tail;
	delete this->head;
}

/*
**==========================
**       Modifiers
**==========================
*/

template < typename T, typename Alloc >
void list<T, Alloc>::assign(iterator first, iterator last)
{
	this->clear();
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

template < typename T, typename Alloc >
void list<T, Alloc>::assign(const_iterator first, const_iterator last)
{
	this->clear();
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

template < typename T, typename Alloc >
void list<T, Alloc>::assign(size_type n, const value_type& val)
{
	this->clear();
	for (size_type i = 0; i < n; i++)
		push_back(val);
}

template < typename T, typename Alloc >
void list<T, Alloc>::push_back(const value_type &val)
{
	node_pointer temp = new node<T>(val);
	temp->next = this->tail;
	temp->prev = this->tail->prev;
	this->tail->prev->next = temp;
	this->tail->prev = temp;
	this->len_size++;
}

template < typename T, typename Alloc >
void list<T, Alloc>::pop_back()
{
	if (this->len_size)
	{
		node_pointer temp = this->tail->prev->prev;
		temp->next = this->tail;
		delete this->tail->prev;
		this->tail->prev = temp;
		this->len_size--;
	}
}

template < typename T, typename Alloc >
void list<T, Alloc>::clear()
{
	while (this->len_size)
		pop_back();
}

} //namesapce ft