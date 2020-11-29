#pragma once

#include "../main.hpp"

template <class Key, class T>
struct BinaryTreeMap
{
	BinaryTreeMap		*parent;
	BinaryTreeMap		*left;
	BinaryTreeMap		*right;
	std::pair<Key,T>	pair;
	size_t				left_height;
	size_t				right_height;
};



namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class map
    {
        public:
            //https://www.cplusplus.com/reference/map/map/value_comp
            class value_compare
            {// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  	            friend class map;
                protected:
  		            Compare comp;
  		            value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	            public:
		        typedef bool result_type;
		        typedef value_type first_argument_type;
		        typedef value_type second_argument_type;

		        bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first);}
	        };
        
            typedef Key												key_type;
		    typedef T												value;
		    typedef std::pair<const key_type, value>			    value_type;
		    typedef std::less<key_type>								key_compare;
		    typedef Alloc											allocator_type;
		    typedef T&                                              reference;
		    typedef const T&                                        const_reference;
		    typedef	T*                                              pointer;
		    typedef	const T*                                        const_pointer;
            typedef size_t											size_type;
            typedef BinaryTreeMap<Key, T>                           Tree;
		    //typedef ft::IteratorMap<Key, T>							iterator;
		    //typedef ft::ConstIteratorMap<Key, T>					const_iterator;
		    //typedef ft::ReverseIteratorMap<Key, T>					reverse_iterator;
		    //typedef ft::ConstReverseIteratorMap<Key, T>				const_reverse_iterator;
		    
        private:
            allocator_type	alloc;
		    key_compare		comp;
		    Tree		    *curr;
		    Tree			*_start;
		    Tree			*_end;
		    size_type		length;
			
		public:
			//main
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			map(iterator first, iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const_iterator first, const_iterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map& x);
			map& operator=(const map& x);
			~map()
	

    };

} //namespace ft