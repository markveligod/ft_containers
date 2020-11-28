#pragma once

#include <cstdlib>

/*
**==========================
** random_access_iterator
**==========================
*/

template < typename T, typename Pointer, typename Reference >
class RandomIt
{
    public:
        typedef Pointer                            	pointer;
        typedef Reference                           reference;
		typedef size_t								size_type;
        typedef RandomIt<T, Pointer, Reference>		curr_class;
		typedef RandomIt<T, T*, T&>              	iterator;

        pointer ptr_array;
    
        RandomIt() { this->ptr_array = NULL;}
		RandomIt(const pointer ptr) {this->ptr_array = ptr;}
		RandomIt(const iterator &other) { *this = other;}
		~RandomIt() {}
    
        curr_class &operator=(const iterator& x)
        {
			this->ptr_array = x.ptr_array;
			return (*this);
		}

		curr_class	operator++(int)
        {
			curr_class temp = *this;
			++this->ptr_array;
			return temp;
		}
		curr_class &operator++() 
        {
			this->ptr_array++;
			return (*this);
		}
		curr_class	operator+(size_type n) const
        {
			curr_class temp = *this;
			temp.ptr_array += n;
			return (temp);
		}
		curr_class &operator+=(size_type n)
        {
			this->ptr_array += n;
			return (*this);
		}
		curr_class	operator--(int)
        {
			curr_class temp = *this;
			--this->ptr_array;
			return (temp);
		}
		curr_class &operator--()
        {
			--this->ptr_array;
			return (*this);
		}
		size_type operator-(curr_class it) const
        {
			return (this->ptr_array - it.ptr_array);
		}
		curr_class	operator-(size_type n) const
        {
			curr_class temp = *this;
			temp -= n;
			return (temp);
		}
		curr_class &operator-=(size_type n)
        {
			this->ptr_array -= n;
			return (*this);
		}
		reference	operator*() { return (*this->ptr_array);}

		pointer operator->() { return (*(&(this->array)));}

		reference	operator[](size_type n) { return (*(this->ptr_array + n));}

        bool operator==(const curr_class &other) const { return (this->ptr_array == other.ptr_array);}
        bool operator!=(const curr_class &other) const { return (this->ptr_array != other.ptr_array);}
};

template < typename T, typename Pointer, typename Reference >
class RevRandomIt
{
    public:
        typedef Pointer                            	pointer;
        typedef Reference                           reference;
		typedef size_t								size_type;
        typedef RevRandomIt<T, Pointer, Reference>	curr_class;
		typedef RevRandomIt<T, T*, T&>              	iterator;

        pointer ptr_array;
    
        RevRandomIt() { this->ptr_array = NULL;}
		RevRandomIt(const pointer ptr) {this->ptr_array = ptr;}
		RevRandomIt(const iterator &other) { *this = other;}
		~RevRandomIt() {}
    
        curr_class &operator=(const iterator& x)
        {
			this->ptr_array = x.ptr_array;
			return (*this);
		}

		curr_class	operator++(int)
        {
			curr_class temp = *this;
			--this->ptr_array;
			return temp;
		}
		curr_class &operator++() 
        {
			this->ptr_array--;
			return (*this);
		}

		curr_class &operator+=(size_type n)
        {
			this->ptr_array -= n;
			return (*this);
		}
		curr_class	operator--(int)
        {
			curr_class temp = *this;
			++this->ptr_array;
			return (temp);
		}
		curr_class &operator--()
        {
			++this->ptr_array;
			return (*this);
		}

		curr_class &operator-=(size_type n)
        {
			this->ptr_array += n;
			return (*this);
		}

		size_type operator-(curr_class it) const { return (this->ptr_array - it.ptr_array);}

		curr_class	operator-(size_type n) const { return curr_class(this->current + n);}

		curr_class	operator+(size_type n) const { return curr_class(this->current - n);}

		reference	operator*() { return (*this->ptr_array);}

		pointer operator->() { return (*(&(this->array)));}

		reference operator[](size_type n) { return (*(*this + n));}

        bool operator==(const curr_class &other) const { return (this->ptr_array == other.ptr_array);}
        bool operator!=(const curr_class &other) const { return (this->ptr_array != other.ptr_array);}
};
