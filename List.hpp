#pragma once

template<typename Type>
class List
{
	private:
		template<typename Type>
		class Node
		{
			public:
				Node *_next;
				Type _data;

				Node(Type &data = Type(), Node *next = NULL)
				{
					this->_data = data;
					this->_next = next;
				}
		};

		int _size;
		Node<Type> *head;

	public:
		List();
		List(List const &other);
		~List();

		List &operator=(List const &other);

		void push_back(Type data);
		int size() const;

};


// https://en.cppreference.com/w/cpp/container/list

template<typename Type>
List<Type>::List()
{
	this->_size = 0;
	this->head = NULL;
}

template<typename Type>
List<Type>::List(List const &other)
{

}

template<typename Type>
List<Type>::~List()
{

}

template<typename Type>
List<Type> &List<Type>::operator=(List<Type> const &other)
{

	return(*this);
}

template<typename Type>
void List<Type>::push_back(Type data)
{
	if (this->head == NULL)
	{
		head = new Node<Type>(data);
	}
	else
	{
		Node<Type> *curr = this->head;
		while (curr->_next != NULL)
			curr = curr->_next;
		curr->_next = new Node<Type>(data);
	}
	this->_size++;
}

template<typename Type>
int List<Type>::size() const
{
	return (this->_size);
}