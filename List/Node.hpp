#pragma once
/**
 * class Node
 * Крутой класс который помогает строить цепочку списка
 *  
 */
template<typename T>
class Node
{
	public:
		Node<T> *_next;
		Node<T> *_prev;
		T _data;

		Node() 
		{
			this->_data = 0;
			this->_next = NULL;
			this->_prev = NULL;
		};
		Node(const T &data, Node<T> *next = NULL, Node<T> *prev = NULL)
		{
			this->_data = data;
			this->_next = next;
			this->_prev = prev;
		}
		Node(const Node<T> &other) {*this = other;}
		~Node() {};

		Node<T> &operator=(const Node<T> &other)
		{
			*this = other;
			return (*this);
		}
};
