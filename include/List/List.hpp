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

		public:
			//main
			explicit list(const allocator_type& alloc = allocator_type());
			explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			list(const list &other);
			list &operator=(const list &other);
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
			
			
	};
}