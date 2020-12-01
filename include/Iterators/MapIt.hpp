#pragma once

#include "../../main.hpp"

/*
**==========================
** bidirectional_iterator
**==========================
*/

template <class Key, class T>
struct BNode
{
	std::pair<Key, T> pair;
	BNode *left;
	BNode *right;
	BNode *parent;
	bool end;
};

template <typename K, typename T, typename Pointer, typename Reference>
	class MapIterator
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
			typedef MapIterator<K, T, Pointer, Reference>		curr_class;
        	typedef MapIterator<K, T, T*, T&>              		iterator;
			pointer _ptr;
		private:
			pointer ptr_next(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer ptr_prev(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};
		public:
			MapIterator(void): _ptr(0) {}
			MapIterator(const pointer ptr): _ptr(ptr) {}
			MapIterator(const iterator &other) { *this = other;}
			
			MapIterator &operator=(const iterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			
			pointer node(void) { return (_ptr);}
			
			value_type &operator*(void) { return (_ptr->pair);}
			
			value_type *operator->(void) { return (&_ptr->pair);}
			
			bool operator==(const curr_class &other) { return (_ptr == other._ptr);}
			bool operator!=(const curr_class &other) { return (!(*this == other));}
			
			MapIterator &operator++(void)
			{
				_ptr = ptr_next(_ptr);
				return (*this);
			}

			MapIterator &operator--(void)
			{
				_ptr = ptr_prev(_ptr);
				return (*this);
			}

			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

	};
	template <typename K, typename T, typename Pointer, typename Reference>
	class ReverseMapIterator
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
			typedef ReverseMapIterator<K, T, Pointer, Reference>		curr_class;
        	typedef ReverseMapIterator<K, T, T*, T&>              		iterator;
			pointer _ptr;
		private:
			pointer ptr_next(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer ptr_prev(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			};
		public:
			ReverseMapIterator(): _ptr(0) {}
			ReverseMapIterator(const pointer ptr): _ptr(ptr) {}
			ReverseMapIterator(const iterator &other) {	*this = other;}

			ReverseMapIterator &operator=(const iterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			
			pointer node() { return (_ptr);}
			
			value_type &operator*(void) { return (_ptr->pair);}

			value_type *operator->(void) { return (&_ptr->pair);}

			bool operator==(const curr_class &other) { return (_ptr == other._ptr);}
			bool operator!=(const curr_class &other) { return (!(*this == other));}
			
			ReverseMapIterator &operator++(void)
			{
				_ptr = ptr_prev(_ptr);
				return (*this);
			}

			ReverseMapIterator &operator--(void)
			{
				_ptr = ptr_next(_ptr);
				return (*this);
			}

			ReverseMapIterator operator++(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ReverseMapIterator operator--(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

	};
	