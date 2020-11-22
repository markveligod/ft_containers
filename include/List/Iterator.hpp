#pragma once

#include "Node.hpp"

template <typename T, typename Pointer, typename Reference>
class Iterator
{
    public:
        typedef Pointer                             pointer;
        typedef Reference                           reference;
        typedef node<T>*                            node_pointer;
        typedef Iterator<T, Pointer, Reference>     curr_class;
        typedef Iterator<T, Pointer, Reference>&    curr_class_reference;
        typedef Iterator<T, T*, T&>                 iterator;
        typedef Iterator<T, T*, T&>&                iterator_reference;
	    typedef Iterator<T, const T*, const T&>     const_iterator;
        typedef Iterator<T, const T*, const T&>&    const_iterator_reference;

    private:
        node_pointer ptr;

    public:
        Iterator() { this->ptr = NULL;}
	    Iterator(const node_pointer ptr) { this->ptr = ptr;}
	    Iterator(const iterator_reference other) { *this = other;}
	    ~Iterator() {}

	    curr_class_reference operator=(const iterator_reference other) 
        {
		    this->ptr = other.ptr;
		    return (*this);
	    }
        reference operator*() const { return (ptr->data);}
	    pointer   operator->() const { return &(this->ptr->data);}
        curr_class_reference operator++() 
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
	    curr_class_reference operator--()
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
        bool operator==(const curr_class_reference other) const { return (this->ptr == other.ptr);}
        bool operator!=(const curr_class_reference other) const { return (this->ptr != other.ptr);}
};

template <typename T, typename Pointer, typename Reference>
class RevIterator
{
    public:
        typedef Pointer                                 pointer;
        typedef Reference                               reference;
        typedef node<T>*                                node_pointer;
        typedef RevIterator<T, Pointer, Reference>      curr_class;
        typedef RevIterator<T, Pointer, Reference>&     curr_class_reference;
        typedef RevIterator<T, T*, T&>                  iterator;
        typedef RevIterator<T, T*, T&>&                 iterator_reference;
	    typedef RevIterator<T, const T*, const T&>      const_iterator;
        typedef RevIterator<T, const T*, const T&>&     const_iterator_reference;

    private:
        node_pointer ptr;

    public:
        RevIterator() { this->ptr = NULL;}
	    RevIterator(const node_pointer ptr) { this->ptr = ptr;}
	    RevIterator(const iterator_reference other) { *this = other;}
	    ~RevIterator() {}

	    curr_class_reference operator=(const iterator_reference other) 
        {
		    this->ptr = other.ptr;
		    return (*this);
	    }
        reference operator*() const { return (ptr->data);}
	    pointer   operator->() const { return &(this->ptr->data);}
        curr_class_reference operator++() 
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
	    curr_class_reference operator--()
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
        bool operator==(const curr_class_reference other) const { return (this->ptr == other.ptr);}
        bool operator!=(const curr_class_reference other) const { return (this->ptr != other.ptr);}
};