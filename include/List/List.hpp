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
			void					push_front(const value_type &val);
			void					pop_front();
			void					clear();
			iterator				insert(iterator position, const value_type& val);
			void					insert(iterator position, size_type n, const value_type& val);
			void					insert(iterator position, iterator first, iterator last);
			void					insert(iterator position, const_iterator first, const_iterator last);
			iterator				erase(iterator position);
			iterator				erase(iterator first, iterator last);
			void					swap(list& x);
			void					resize (size_type n, value_type val = value_type());

			//Operations
			void					splice(iterator position, list& x);
			void					splice(iterator position, list& x, iterator i);
			void					splice(iterator position, list& x, iterator first, iterator last);
			void					remove(const value_type& val);
			void					unique();
			
			template <class Predicate>
			void remove_if(Predicate pred)
			{
				iterator begin = this->begin();
				iterator end = this->end();

				while (begin != end)
				{
					if (pred(*begin))
						begin = this->erase(begin);
					else
						++begin;
				}
			}
			
			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				iterator begin = this->begin();
				iterator end = this->end();

				++begin;
				while (begin != end)
				{
					if (binary_pred(*begin, begin.ptr->prev->data))
						begin = erase(begin);
					else
						++begin;
				}
			}

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
list<T, Alloc>::list(const list<T, Alloc> &other)
{
	this->init_default_param(other.alloc);
	this->assign(other.begin(), other.end());
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
	node_pointer temp = new node<value_type>(val);
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
void list<T, Alloc>::push_front(const value_type &val)
{
	node_pointer ptr = new node<value_type>(val);
	ptr->prev = this->head;
	ptr->next = this->head->next;
	this->head->next->prev = ptr;
	this->head->next = ptr;
	this->len_size++;
}

template < typename T, typename Alloc >
void list<T, Alloc>::pop_front()
{
	if (this->len_size)
	{
		node_pointer temp = this->head->next->next;
		temp->prev = this->head;
		delete this->head->next;
		this->head->next = temp;
		this->len_size--;
	}
}

template < typename T, typename Alloc >
void list<T, Alloc>::clear()
{
	while (this->len_size)
		pop_back();
}

template < typename T, typename Alloc >
list<T, Alloc>::iterator list<T, Alloc>::insert(iterator position, const value_type& val)
{
	node_pointer temp = new node<value_type>(val);
	temp->prev = position.ptr->prev;
	temp->next = position.ptr;
	temp->prev->next = temp;
	temp->next->prev = temp;
	this->len_size++;
	return (iterator(temp));
}

template < typename T, typename Alloc >
void list<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
	for (size_type i = 0; i < n; i++)
		insert(position, val);
}

template < typename T, typename Alloc >
void list<T, Alloc>::insert(iterator position, iterator first, iterator last)
{
	while (first != last)
	{
		insert(position, *first);
		++first;
	}
}

template < typename T, typename Alloc >
void list<T, Alloc>::insert(iterator position, const_iterator first, const_iterator last)
{
	while (first != last)
	{
		insert(position, *first);
		++first;
	}
}

template < typename T, typename Alloc >
list<T, Alloc>::iterator list<T, Alloc>::erase(iterator position)
{
	node_pointer temp = position.ptr;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	position++;
	delete temp;
	this->len_size--;
	return (position);
}

template < typename T, typename Alloc >
list<T, Alloc>::iterator list<T, Alloc>::erase(iterator first, iterator last)
{
	while (first != last) 
		first = this->erase(first);
	return (first);
}

template<typename T, typename Alloc >
void list<T, Alloc>::swap(list<T, Alloc> &other)
{
	list<T, Alloc> temp = *this;
	*this = other;
	other = temp;
}

template<typename T, typename Alloc >
void list<T, Alloc>::resize(size_type n, value_type val)
{
	if (this->len_size < n)
	{
		while (this->len_size < n)
			this->push_back(val);
	}
	else
	{
		while (this->len_size > n)
			this->pop_back();
	}
}

/*
**==========================
**       Operations
**==========================
*/

template<typename T, typename Alloc >
void list<T, Alloc>::splice(iterator position, list& x)
{
	this->insert(position, x.begin(), x.end());
	x.clear();
}

template<typename T, typename Alloc >
void list<T, Alloc>::splice(iterator position, list& x, iterator i)
{
	this->insert(position, i.ptr->data);
	x.erase(i);
}

template<typename T, typename Alloc >
void list<T, Alloc>::splice(iterator position, list& x, iterator first, iterator last)
{
	this->insert(position, first, last);
	x.erase(first, last);
}

template<typename T, typename Alloc >
void list<T, Alloc>::remove(const value_type& val)
{
	iterator begin = this->begin();
	iterator end = this->end();
	while (begin != end)
	{
		if (*begin == val)
			begin = this->erase(pos);
		else
			++begin;
	}
}

template<typename T, typename Alloc >
void list<T, Alloc>::unique()
{
	iterator begin = this->begin();
	iterator end = this->end();

	++begin;
	while (begin != end)
	{
		if (*begin == begin.ptr->prev->data)
			begin = erase(begin);
		else
			++begin;
	}
}

} //namesapce ft