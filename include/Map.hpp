#pragma once

#include "../main.hpp"
#include "Iterators/MapIt.hpp"

//https://www.youtube.com/watch?v=jDM6_TnYIqE

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class Key, class T, class Compare=std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key 																		key_type;
			typedef T 																			mapped_type;
			typedef std::pair<const key_type, mapped_type> 										value_type;
			typedef Compare 																	key_compare;
			typedef Alloc 																		allocator_type;
			typedef T& 																			reference;
			typedef const T& 																	const_reference;
			typedef T* 																			pointer;
			typedef const T* 																	const_pointer;
			typedef size_t 																		size_type;
			typedef BNode<key_type, mapped_type>* 												node;
			typedef MapIterator<key_type, mapped_type, pointer, reference> 						iterator;
			typedef ReverseMapIterator<key_type, mapped_type, pointer, reference> 				reverse_iterator;
			typedef MapIterator<key_type, mapped_type, const_pointer, const_reference> 			const_iterator;
			typedef ReverseMapIterator<key_type, mapped_type, const_pointer, const_reference>	const_reverse_iterator;
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {} // constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
		private:
			allocator_type _allocator;
			key_compare _comp;
			node _root;
			size_type _length;

			node _new_node(key_type key, mapped_type value, node parent, bool end = false)
			{
				node temp = new BNode<key_type, mapped_type>();
				temp->pair = std::make_pair(key, value);
				temp->right = 0;
				temp->left = 0;
				temp->parent = parent;
				temp->end = end;
				return (temp);
			}
			void _free_tree(node n)
			{
				if (n->right)
					_free_tree(n->right);
				if (n->left)
					_free_tree(n->left);
				delete n;
			}
			node _insert_node(node n, key_type key, mapped_type value, bool end = false)
			{
				if (n->end)
				{
					if (!n->left)
					{
						n->left = _new_node(key, value, n, end);
						return (n->left);
					}
					return (_insert_node(n->left, key, value));
				}
				if (key < n->pair.first && !end)
				{
					if (!n->left)
					{
						n->left = _new_node(key, value, n, end);
						return (n->left);
					}
					else
						return (_insert_node(n->left, key, value));
				}
				else
				{
					if (!n->right)
					{
						n->right = _new_node(key, value, n, end);
						return (n->right);
					}
					else
						return(_insert_node(n->right, key, value));
				}
			}
			node _find(node n, key_type key) const
			{
				node temp;
				if (!n->end && n->pair.first == key && n->parent)
					return (n);
				if (n->right)
				{
					if ((temp = _find(n->right, key)))
						return (temp);
				}
				if (n->left)
				{
					if ((temp = _find(n->left, key)))
						return (temp);
				}
				return (0);
			}
			void _delete_node(node n)
			{
				node parent = n->parent;
				if (!n->left && !n->right)
				{
					if (parent->right == n)
						parent->right = 0;
					else
						parent->left = 0;
					delete n;
					return ;
				}
				if (n->right && !n->left)
				{
					if (parent->right == n)
						parent->right = n->right;
					else
						parent->left = n->right;
					n->right->parent = parent;
					delete n;
					return ;
				}
				if (n->left && !n->right)
				{
					if (parent->right == n)
						parent->right = n->left;
					else
						parent->left = n->left;
					n->left->parent = parent;
					delete n;
					return ;
				}
				node next = (++iterator(n)).node();
				if (!next)
					next = (--iterator(n)).node();
				ft::swap(next->pair, n->pair);
				_delete_node(next);
			}
			void _init_tree(void)
			{
				_root = _new_node(key_type(), mapped_type(), 0);
				_root->right  = _new_node(key_type(), mapped_type(), _root, true);
				_length = 0;
			}
			node _end(void) const
			{
				return (_root->right);
			}
		public:
			//Main
			explicit map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type());
			map(const map<Key, T> &other);
			~map();
			map &operator=(const map<Key, T> &other);

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			{
				this->_allocator = alloc;
				this->_comp = comp;
				this->_init_tree();
				this->insert(first, last);
			}

			//Iterators
			iterator begin();
			const_iterator begin() const;
			
			iterator		end()		{ return (iterator(this->_end()));}
			const_iterator	end() const	{ return (const_iterator(this->_end()));}

			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			
			reverse_iterator		rend()			{ return (reverse_iterator(this->_root));}
			const_reverse_iterator	rend() const	{ return (const_reverse_iterator(this->_root));}

			//Capacity
			bool		empty() const		{ return (this->_length == 0);}
			size_type	size() const		{ return (this->_length);}
			size_type	max_size() const	{ return (std::numeric_limits<size_type>::max() / (sizeof(BNode<key_type, mapped_type>)));}

			//Element access
			mapped_type &operator[](const key_type& k);
			
			//Modifiers
			std::pair<iterator, bool> insert(const value_type &value);
			iterator insert(iterator position, const value_type &value);
			void erase(iterator position);
			size_type erase(const key_type &value);
			void erase(iterator first, iterator last);
			void swap(map &x);
			void clear();
			
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->insert(*first);
					++first;
				}
			}

			//Observers
			key_compare		key_comp(void) const	{ return (_comp);}
			value_compare	value_comp(void) const	{ return (value_compare(this->_comp));}

			//Operations
			iterator find(const key_type &value);
			const_iterator find(const key_type &value) const;
			size_type count(const key_type &value) const;
			iterator lower_bound(const key_type &key);
			const_iterator lower_bound(const key_type &key) const;
			iterator upper_bound(const key_type &key);
			const_iterator upper_bound(const key_type &key) const;

			std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
			std::pair<iterator, iterator> equal_range(const key_type &k)
			{
				return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
	};

/*
**==========================
**          Main
**==========================
*/

template <class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type alloc)
{
	this->_allocator = alloc;
	this->_comp = comp;
	this->_init_tree();
}

template <class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::map(const map<Key, T> &other)
{
	this->_init_tree();
	*this = other;
}

template <class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::~map()
{
	this->_free_tree(this->_root);	
}

template <class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc> &map<Key, T, Compare, Alloc>::operator=(const map<Key, T> &other)
{
	this->clear();
	this->insert(other.begin(), other.end());
	return (*this);
}

/*
**==========================
**       Iterators
**==========================
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::begin()
{
	node n = this->_root;
	if (!n->left && !n->right)
		return (this->end());
	if (!n->left && n->right)
		n = n->right;
	while (n->left)
		n = n->left;
	return (iterator(n));
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::begin() const
{
	node n = this->_root;
	if (!n->left && !n->right)
		return (this->end());
	if (!n->left && n->right)
		n = n->right;
	while (n->left)
		n = n->left;
	return (const_iterator(n));
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::reverse_iterator map<Key, T, Compare, Alloc>::rbegin()
{
	iterator i = this->end();
	i--;
	return (reverse_iterator(i.node()));
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin() const
{
	iterator i = this->end();
	i--;
	return (const_reverse_iterator(i.node()));
}

/*
**==========================
**     Element access
**==========================
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::mapped_type &map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
	iterator tmp = this->find(k);
	if (tmp != this->end())
	{
		return tmp->second;
	}
	return (this->insert(std::make_pair(k, mapped_type())).first->second);
}

/*
**==========================
**        Modifiers
**==========================
*/

template <class Key, class T, class Compare, class Alloc >
std::pair<typename map<Key, T, Compare, Alloc>::iterator, bool> map<Key, T, Compare, Alloc>::insert(const value_type &value)
{
	iterator temp;
	if ((temp = this->find(value.first)) != this->end())
		return (std::make_pair(temp, false));
	++this->_length;
	return (std::make_pair(iterator(this->_insert_node(this->_root, value.first, value.second)), true));
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &value)
{
	iterator temp;
	if ((temp = this->find(value.first)) != this->end())
		return (temp);
	++this->_length;
	return (iterator(_insert_node(position.node(), value.first, value.second)));
}

template <class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::erase(iterator position)
{
	this->_delete_node(position.node());
	--this->_length;
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::erase(const key_type &value)
{
	size_type i = 0;
	iterator item;
	while ((item = this->find(value)) != this->end())
	{
		this->erase(item);
		++i;
	}
	return (i);
}

template <class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	while (first != last)
		this->erase(first++);
}

template <class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::swap(map &x)
{
	map<Key, T, Compare, Alloc> temp = *this;
	*this = x;
	x = temp;
}

template <class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::clear()
{
	this->erase(this->begin(), this->end());
}

/*
**==========================
**       Operations
**==========================
*/

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const key_type &value)
{
	if (this->empty())
		return (this->end());
	node temp = this->_find(this->_root, value);
	if (temp)
		return (iterator(temp));
	return (this->end());
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type &value) const
{
	if (this->empty())
		return (this->end());
	node temp = this->_find(this->_root, value);
	if (temp)
		return (const_iterator(temp));
	return (this->end());
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count(const key_type &value) const
{
	const_iterator it_begin = this->begin();
	const_iterator it_end = this->end();

	while (it_begin != it_end)
	{
		if (it_begin->first == value)
			return (1);
		++it_begin;
	}
	return (0);
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type &key)
{
	iterator it_begin = this->begin();
	iterator it_end = this->end();
	while (it_begin != it_end)
	{
		if (this->_comp(it_begin->first, key) <= 0)
			return (it_begin);
		++it_begin;
	}
	return (it_end);
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type &key) const
{
	const_iterator it_begin = this->begin();
	const_iterator it_end = this->end();
	while (it_begin != it_end)
	{
		if (this->_comp(it_begin->first, key) <= 0)
			return (it_begin);
		++it_begin;
	}
	return (it_end);
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type &key)
{
	iterator it_begin = this->begin();
	iterator it_end = this->end();
	while (it_begin != it_end)
	{
		if (it_begin->first != key && this->_comp(it_begin->first, key) <= 0)
			return (it_begin);
		++it_begin;
	}
	return (it_end);
}

template <class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type &key) const
{
	const_iterator it_begin = this->begin();
	const_iterator it_end = this->end();
	while (it_begin != it_end)
	{
		if (it_begin->first != key && this->_comp(it_begin->first, key) <= 0)
			return (it_begin);
		++it_begin;
	}
	return (it_end);
}

} //namespace ft