#pragma once

template<typename T>
class Node
{
	public:
		Node *_next;
        Node *_prev;
		T _data;

		Node(T &data = T(), Node *next = NULL, Node *prev = NULL)
		{
			this->_data = data;
			this->_next = next;
            this->_prev = prev;
		}
};
