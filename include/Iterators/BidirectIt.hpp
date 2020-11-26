#pragma once

#include "Node.hpp"

/*
**==========================
** bidirectional_iterator
**==========================
*/

template <typename T, typename Pointer, typename Reference>
class BidirectIt
{
    public:
        typedef Pointer                            		pointer;
        typedef Reference                           	reference;
        typedef node<T>*                            	node_pointer;
        typedef BidirectIt<T, Pointer, Reference>		curr_class;
        typedef BidirectIt<T, T*, T&>              		iterator;
        node_pointer ptr;

        BidirectIt() { this->ptr = NULL;}
	    BidirectIt(const node_pointer ptr) { this->ptr = ptr;}
	    BidirectIt(const iterator &other) { *this = other;}
	    ~BidirectIt() {}

	    curr_class &operator=(const iterator &other) 
        {
		    this->ptr = other.ptr;
		    return (*this);
	    }
        reference operator*() const { return (ptr->data);}
        curr_class &operator++() 
        {
		    ptr = ptr->next;
		    return (*this);
	    }
	    curr_class  operator++(int) 
        {
		    curr_class temp = *this;
		    ptr = ptr->next;
		    return (temp);
	    }
	    curr_class &operator--()
        {
		    ptr = ptr->prev;
		    return (*this);
	    }

	    curr_class  operator--(int) 
        {
		    curr_class temp = *this;
		    ptr = ptr->prev;
		    return (temp);
	    }
		pointer operator->() const { return &(this->ptr->data); }
        bool operator==(const curr_class &other) const { return (this->ptr == other.ptr);}
        bool operator!=(const curr_class &other) const { return (this->ptr != other.ptr);}
};

template <typename T, typename Pointer, typename Reference>
class RevBidirectIt
{
    public:
        typedef Pointer                                 pointer;
        typedef Reference                               reference;
        typedef node<T>*                                node_pointer;
        typedef RevBidirectIt<T, Pointer, Reference>      curr_class;
        typedef RevBidirectIt<T, T*, T&>                  iterator;
        node_pointer ptr;

        RevBidirectIt() { this->ptr = NULL;}
	    RevBidirectIt(const node_pointer ptr) { this->ptr = ptr;}
	    RevBidirectIt(const iterator &other) { *this = other;}
	    ~RevBidirectIt() {}

	    curr_class &operator=(const iterator &other) 
        {
		    this->ptr = other.ptr;
		    return (*this);
	    }
        reference operator*() const { return (ptr->data);}
        curr_class &operator++() 
        {
		    ptr = ptr->prev;
		    return (*this);
	    }
	    curr_class  operator++(int) 
        {
		    curr_class temp = *this;
		    ptr = ptr->prev;
		    return (temp);
	    }
	    curr_class &operator--()
        {
		    ptr = ptr->next;
		    return (*this);
	    }

	    curr_class  operator--(int) 
        {
		    curr_class temp = *this;
		    ptr = ptr->next;
		    return (temp);
	    }
		pointer operator->() const { return &(this->ptr->data); }
        bool operator==(const curr_class &other) const { return (this->ptr == other.ptr);}
        bool operator!=(const curr_class &other) const { return (this->ptr != other.ptr);}
};