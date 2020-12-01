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
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};
		private:
			allocator_type _allocator;
			key_compare _comp;
			node _root;
			size_type _length;

			node _new_node(key_type key, mapped_type value, node parent, bool end = false)
			{
				node el = new BNode<key_type, mapped_type>();
				el->pair = std::make_pair(key, value);
				el->right = 0;
				el->left = 0;
				el->parent = parent;
				el->end = end;
				return (el);
			};
			void _free_tree(node n)
			{
				if (n->right)
					_free_tree(n->right);
				if (n->left)
					_free_tree(n->left);
				delete n;
			};
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
			};
			node _find(node n, key_type key) const
			{
				node tmp;
				if (!n->end && n->pair.first == key && n->parent)
					return (n);
				if (n->right)
				{
					if ((tmp = _find(n->right, key)))
						return (tmp);
				}
				if (n->left)
				{
					if ((tmp = _find(n->left, key)))
						return (tmp);
				}
				return (0);
			};
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
			};
			void _init_tree(void)
			{
				_root = _new_node(key_type(), mapped_type(), 0);
				_root->right  = _new_node(key_type(), mapped_type(), _root, true);
				_length = 0;
			};
			node _end(void) const
			{
				return (_root->right);
			};
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
			
			
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}


			
			size_type erase(const key_type &value)
			{
				int i = 0;
				iterator item;
				while ((item = find(value)) != end())
				{
					erase(item);
					++i;
				};
				return (i);
			};
			void erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			};
			void swap(map &x)
			{
				ft::swap(_length, x._length);
				ft::swap(_root, x._root);
			};
			void clear(void)
			{
				erase(begin(), end());
			};
			key_compare key_comp(void) const
			{
				return (_comp);
			};
			value_compare value_comp(void) const
			{
				return (value_compare(this->_comp));
			};
			iterator find(const key_type &value)
			{
				if (empty())
					return (end());
				node tmp = _find(_root, value);
				if (tmp)
					return (iterator(tmp));
				return (end());
			};
			const_iterator find(const key_type &value) const
			{
				if (empty())
					return (end());
				node tmp = _find(_root, value);
				if (tmp)
					return (const_iterator(tmp));
				return (end());
			};
			size_type count(const key_type &value) const
			{
				size_t c = 0;
				const_iterator it = begin();

				while (it != end())
				{
					if (it->first == value)
						++c;
					++it;
				}
				return (c);
			};
			iterator lower_bound(const key_type &key)
			{
				iterator it = begin();
				while (it != end())
				{
					if (this->_comp(it->first, key) <= 0)
						return (it);
					++it;
				}
				return (end());
			};
			const_iterator lower_bound(const key_type &key) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (this->_comp(it->first, key) <= 0)
						return (it);
					++it;
				}
				return (end());
			};
			iterator upper_bound(const key_type &key)
			{
				iterator it = begin();
				while (it != end())
				{
					if (it->first != key && this->_comp(it->first, key) <= 0)
						return (it);
					++it;
				};
				return (end());
			};
			const_iterator upper_bound(const key_type &key) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (it->first != key && this->_comp(it->first, key) <= 0)
						return (it);
					++it;
				};
				return (end());
			};
			std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			};
			std::pair<iterator, iterator> equal_range(const key_type &k)
			{
				return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			};
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
};

} //namespace ft