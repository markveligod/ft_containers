#pragma once
#include "./Node.hpp"

// https://stackoverflow.com/questions/4659162/int-argument-in-operator

    template<class T>
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

    template<class T>
    class RevIterator
    {
        private:
            Node<T> *node;
        public:
            RevIterator() {this->node = NULL;}

            RevIterator(Node<T> *data)
            {
                this->node = data;
            }

            RevIterator(const RevIterator &other)
            {
                *this = other;
            }

            RevIterator &operator=(const RevIterator &other)
            {
                this->node = other.node;
                return (*this);
            }

            ~RevIterator() {}

            RevIterator &operator++()
            {
                this->node = this->node->_prev;
                return (*this);
            }

            RevIterator operator++(int)
            {
                RevIterator temp = *this;
                this->operator++();
                return (temp);
            }

            RevIterator &operator--()
            {
                this->node = this->node->_next;
                return (*this);
            }

            RevIterator operator--(int)
            {
                RevIterator temp = *this;
                this->operator--();
                return (temp);
            }

            bool operator==(const RevIterator<T> &other) const
            {
                return (this->node == other.node);
            }

            bool operator!=(const RevIterator<T> &other) const
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
