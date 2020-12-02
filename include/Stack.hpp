#pragma once

#include "../main.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack 
	{
		public:
			typedef T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;
			container_type		cont;

			//Member function
			explicit			stack (const container_type& ctnr = container_type())	{ this->cont = ctnr;}
			bool				empty() const											{ return (this->cont.empty());}
			size_type			size() const											{ return (this->cont.size());}
			value_type			&top()													{ return (this->cont.back());}
			const value_type	&top() const											{ return (this->cont.back());}
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
bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs.cont == rhs.cont);}

template <class T, class Container>
bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs.cont != rhs.cont);}

template <class T, class Container>
bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs.cont < rhs.cont);}

template <class T, class Container>
bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs.cont > rhs.cont);}

template <class T, class Container>
bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs.cont <= rhs.cont);}

template <class T, class Container>
bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (lhs.cont >= rhs.cont);}

} // namespace ft