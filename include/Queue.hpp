#pragma once

#include "../main.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue 
	{
		public:
			typedef T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;
			container_type		cont;

			//Member function
			explicit			queue (const container_type& ctnr = container_type())	{ this->cont = ctnr;}
			bool				empty() const											{ return (this->cont.empty());}
			size_type			size() const											{ return (this->cont.size());}
			value_type			&front()												{ return (this->cont.front());}
			const value_type	&front() const											{ return (this->cont.front());}
			value_type			&back()													{ return (this->cont.back());}
			const value_type	&back() const											{ return (this->cont.back());}
			void				push (const value_type& val)							{ this->cont.push_back(val);}
			void				pop()													{ this->cont.pop_back();}
	};

/*
**==========================
**   Non-member function 
**		overloads
**==========================
*/

template <class T, class Container>
bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs) { return (lhs.cont == rhs.cont);}

template <class T, class Container>
bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) { return (lhs.cont != rhs.cont);}

template <class T, class Container>
bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs) { return (lhs.cont < rhs.cont);}

template <class T, class Container>
bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs) { return (lhs.cont > rhs.cont);}

template <class T, class Container>
bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) { return (lhs.cont <= rhs.cont);}

template <class T, class Container>
bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs) { return (lhs.cont >= rhs.cont);}

} // namespace ft