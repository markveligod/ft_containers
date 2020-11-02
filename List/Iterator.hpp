#pragma once
#include "./Node.hpp"

template<typename T>
class Iterator
{
    protected:
        Node<T> *it;
    public:
        Iterator(Node<T> *ptr = NULL)
        {
            this->it = ptr;
        }
        Iterator<T> &operator++()
        {
            this->it = this->it->_next;
            return (*this);
        }
        Iterator<T> &operator--()
        {
            this->it = this->it->_prev;
            return (*this);
        }
        bool operator==(const Iterator<T> &other) const
        {
            return (this->it == other.it);
        }
        bool operator!=(const Iterator<T> &other) const
        {
            return (this->it != other.it);
        }
        T &operator*()
        {
            return (this->it->_data);
        }
};

template<typename T>
class Const_iterator: public Iterator<T>
{
   
    public:
        Const_iterator(Node<T> *ptr = NULL)
        {
            this->it = ptr;
        }
};

template<typename T>
class Reverse_iterator
{
    protected:
        Node<T> *it;
    public:
        Reverse_iterator(Node<T> *ptr = NULL)
        {
            this->it = ptr;
        }
        Reverse_iterator<T> &operator++()
        {
            this->it = this->it->_prev;
            return (*this);
        }
        Reverse_iterator<T> &operator--()
        {
            this->it = this->it->_next;
            return (*this);
        }
        bool operator==(const Reverse_iterator<T> &other) const
        {
            return (this->it == other.it);
        }
        bool operator!=(const Reverse_iterator<T> &other) const
        {
            return (this->it != other.it);
        }
        T &operator*()
        {
            return (this->it->_data);
        }
};

template<typename T>
class Const_reverse_iterator: public Reverse_iterator<T>
{
    public:
        Const_reverse_iterator(Node<T> *ptr = NULL)
        {
            this->it = ptr;
        }
};