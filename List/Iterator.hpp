#pragma once
#include "./Node.hpp"

// https://stackoverflow.com/questions/4659162/int-argument-in-operator

template<typename T>
class Iterator
{
    private:
        Node<T> *node;
    public:
        Iterator() {this->node = NULL;}

        Iterator(Node<T> *data)
        {
            this->node = data;
        }

        Iterator(const Iterator &other)
        {
            *this = other;
        }

        Iterator &operator=(const Iterator &other)
        {
            this->node = other.node;
            return (*this);
        }

        ~Iterator() {}

        Iterator &operator++()
        {
            this->node = this->node->_next;
            return (*this);
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            this->operator++();
            return (temp);
        }

        Iterator &operator--()
        {
            this->node = this->node->_prev;
            return (*this);
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            this->operator--();
            return (temp);
        }

        bool operator==(const Iterator<T> &other) const
        {
            return (this->node == other.node);
        }

        bool operator!=(const Iterator<T> &other) const
        {
            return (this->node != other.node);
        }

        T &operator*()
		{
			return (this->node->_data);
		}

        Node<T> *getNode() const
        {
            return (this->node);
        }

};

template<typename T>
class Const_iterator
{
     private:
        Node<T> *node;
    public:
        Const_iterator() {this->node = NULL;}

        Const_iterator(Node<T> *data)
        {
            this->node = data;
        }

        Const_iterator(const Const_iterator &other)
        {
            *this = other;
        }

        Const_iterator &operator=(const Const_iterator &other)
        {
            this->node = other.node;
            return (*this);
        }

        ~Const_iterator() {}

        Const_iterator &operator++()
        {
            this->node = this->node->_next;
            return (*this);
        }

        Const_iterator operator++(int)
        {
            Const_iterator temp = *this;
            this->operator++();
            return (temp);
        }

        Const_iterator &operator--()
        {
            this->node = this->node->_prev;
            return (*this);
        }

        Const_iterator operator--(int)
        {
            Const_iterator temp = *this;
            this->operator--();
            return (temp);
        }

        bool operator==(const Const_iterator<T> &other) const
        {
            return (this->node == other.node);
        }

        bool operator!=(const Const_iterator<T> &other) const
        {
            return (this->node != other.node);
        }

        T &operator*()
		{
			return (this->node->_data);
		}

        Node<T> *getNode() const
        {
            return (this->node);
        }
};

template<typename T>
class Reverse_iterator
{
    
};

template<typename T>
class Const_reverse_iterator
{
    
};