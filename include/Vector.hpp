#pragma once

#include "../main.hpp"
#include "Iterators/RandomIt.hpp"

namespace ft
{

	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
			typedef	Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;
			typedef RandomIt<T, T*, T&>								iterator;
			typedef RandomIt<T, const T*, const T&>					const_iterator;
			typedef RevRandomIt<T, T*, T&>							reverse_iterator;
			typedef RevRandomIt<T, const T*, const T&>				const_reverse_iterator;
		private:
			pointer			ptr;
			allocator_type	alloc;
			size_type		len_size;
			size_type		cap;
			size_type		gold_up;

			void init_def()
			{
				this->alloc = alloc;
				this->len_size = 0;
				this->ptr = value_type();
				this->cap = 0;
				this->gold_up = (1 + sqrt(5)) / 2;
			}

		public:
			//Main
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			vector(iterator first, iterator last, const allocator_type& alloc = allocator_type());
			vector(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type());
			vector(const vector& x);
			vector &operator=(const vector& x);
			~vector();

			//Iterators
			iterator				begin()			{ return iterator(this->ptr);}
			const_iterator			begin() const	{ return const_iterator(this->ptr);}
			iterator				end()			{ return iterator(&this->ptr[this->len_size]);}
			const_iterator			end() const		{ return const_iterator(&this->ptr[this->len_size]);}
			reverse_iterator		rbegin()		{ return reverse_iterator(&this->ptr[this->len_size - 1]);}
			const_reverse_iterator	rbegin() const	{ return reverse_iterator(&this->ptr[this->len_size - 1]);}
			reverse_iterator		rend()			{ return reverse_iterator(this->ptr - 1);}
			const_reverse_iterator	rend() const	{ return reverse_iterator(this->ptr - 1);}

	};

/*
**==========================
**          Main
**==========================
*/

template < typename T, typename Alloc >
vector<T, Alloc>::vector(const allocator_type& alloc)
{
	(void)alloc;
	this->init_def();
}

template < typename T, typename Alloc >
vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
{
	this->init_def();
	this->gold_up = (1 + sqrt(5)) / 2;
    this->ptr = static_cast<pointer>(operator new(sizeof(value_type) * n));
    this->len_size = n;
    this->cap = n;
    for (size_type i = 0; i < n; i++)
        this->ptr[i] = val;
}

template < typename T, typename Alloc >
vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc)
{
	this->init_def();
	this->cap = first - last;
	this->len_size = this->cap;
	this->ptr = static_cast<pointer>(operator new(sizeof(value_type) * this->len_size));
	this->assign(first, last);
}

template < typename T, typename Alloc >
vector<T, Alloc>::vector(const_iterator first, const_iterator last, const allocator_type& alloc)
{
	this->init_def();
	this->cap = first - last;
	this->len_size = this->cap;
	this->ptr = static_cast<pointer>(operator new(sizeof(value_type) * this->len_size));
	this->assign(first, last);
}

template < typename T, typename Alloc >
vector<T, Alloc>::vector(const vector& x)
{

}

template < typename T, typename Alloc >
typename vector<T, Alloc>::vector &vector<T, Alloc>::operator=(const vector<T, Alloc>& x)
{

}

template < typename T, typename Alloc >
vector<T, Alloc>::~vector()
{

}




} //ft namespace