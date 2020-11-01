#pragma once
#include "./Node.hpp"

template<typename T>
class Iterator
{
    private:
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