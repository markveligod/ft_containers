#pragma once

/*
**==========================
**         Includes
**==========================
*/
#include <cstdlib>
#include <cstring>
#include "Iterator.hpp"

namespace ft
{
    template<class T>
    class vector
    {
        private:
            T *v_array;
            size_t v_capacity;
            size_t v_size;

        public:
            typedef Iterator<T> 	iterator;
			typedef Iterator<T> 	const_iterator;
			typedef RevIterator<T> 	reverse_iterator;
			typedef RevIterator<T>	const_reverse_iterator;

            //main
            vector();
            vector(size_t count, T const &data);
            vector(iterator first, iterator last);
            vector(vector const &other);
            ~vector();
            vector &operator=(vector const &other);

            //iterators
            

            //Capacity
            size_t 					size() const {return (this->v_size);}
			bool					empty() const {return ((this->v_size == 0) ? true : false);}
			size_t					max_size() const {return ((std::numeric_limits<size_t>::max() / (sizeof(T))) / 2);}
            void                    reserve (size_t count);

            //Element access

            //Modifiers
            void assign(size_t n, const T &data);
            void assign(iterator first, iterator last);
            void clear();
			

    };

/*
**==========================
**       Constructor
**       Destructor
**       operator=
**==========================
*/

template<class T>
vector<T>::vector()
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
}

template<class T>
vector<T>::vector(size_t count, T const &data)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->assign(count, data);
}

template<class T>
vector<T>::vector(iterator first, iterator last)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->assign(first, last);
}

template<class T>
vector<T>::vector(vector const &other)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = other.v_size;
    this->reserve(other.v_capacity);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(other.v_array), other.v_size * sizeof(T));
}

template<class T>
vector<T>::~vector()
{
    this->clear();
}

/*
**==========================
**        Capacity
**==========================
*/

template<class T>
void vector<T>::reserve(size_t count)
{
    if (count > this->v_capacity)
    {
        T *temp = new T(count);
        if (this->v_size > 0)
        {
            std::memcpy(static_cast<void *>(temp), static_cast<void *>(this->v_array), this->v_size * sizeof(T));
            delete [] this->v_array;
        }
        this->v_capacity = count;
        this->v_array = temp;
    }
}

/*
**==========================
**        Modifiers
**==========================
*/

template<class T>
void vector<T>::assign(size_t n, const T &data)
{

}

template<class T>
void vector<T>::assign(iterator first, iterator last)
{

}

template<class T>
void vector<T>::clear()
{
    delete [] this->v_array;
    this->v_size = 0;
    this->v_capacity = 0;
}


} //namespace