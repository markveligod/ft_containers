#pragma once

/*
**==========================
**         Includes
**==========================
*/
#include <cstdlib>
#include <cstring>
#include "VecIterator.hpp"

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
            typedef VecIterator<T> 	iterator;
			typedef VecIterator<T> 	const_iterator;
			typedef VecRevIterator<T> 	reverse_iterator;
			typedef VecRevIterator<T>	const_reverse_iterator;

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
            size_t                  capacity() const {return (this->v_capacity);}
			bool					empty() const {return ((this->v_size == 0) ? true : false);}
			size_t					max_size() const {return ((std::numeric_limits<size_t>::max() / sizeof(T)));}
            void                    reserve (size_t count);

            //Element access
            T &operator[](size_t count) {return (*(this->v_array + count));}
            T const &operator[](size_t count) const {return (*(this->v_array + count));}

            //Modifiers
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
    this->v_array = static_cast<T*>(operator new(sizeof(T) * count));
    this->v_size = count;
    this->v_capacity = count;
    for (size_t i = 0; i < count; i++)
        this->v_array[i] = data;
}
/*
template<class T>
vector<T>::vector(iterator first, iterator last)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    
}
*/
template<class T>
vector<T>::vector(vector const &other)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    this->reserve(other.v_capacity);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(other.v_array), other.v_size * sizeof(T));
    this->v_size = other.v_size;
}

template<class T>
vector<T>::~vector()
{
    this->clear();
}

template<class T>
vector<T> &vector<T>::operator=(vector<T> const &other)
{
    this->clear();
    this->reserve(other.v_capacity);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(other.v_array), other.v_size * sizeof(T));
    this->v_size = other.v_size;
    return (*this);
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
        T *temp = static_cast<T*>(operator new(sizeof(T) * count));;
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
void vector<T>::clear()
{
    if (this->v_size > 0)
        delete [] this->v_array;
    this->v_size = 0;
    this->v_capacity = 0;
    this->v_array = NULL;
}


} //namespace