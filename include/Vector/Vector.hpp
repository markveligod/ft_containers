#pragma once

/*
**==========================
**         Includes
**==========================
*/
#include <cstdlib>
#include <cstring>
#include <string>
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
            iterator                begin() { return (iterator(this->v_array));}
	        const_iterator          begin() const { return (const_iterator(this->v_array));}
	        reverse_iterator        rbegin() { return (reverse_iterator(&(this->v_array[this->v_size])));}
	        const_reverse_iterator  rbegin() const { return (const_reverse_iterator(&(this->v_array[this->v_size])));}
	        iterator                end() { return (iterator(&(this->v_array[this->v_size])));}
	        const_iterator          end() const { return (const_iterator(&(this->v_container[this->v_size])));}
	        reverse_iterator        rend() { return (reverse_iterator(this->v_array));}
	        const_reverse_iterator  rend() const { return (const_reverse_iterator(this->v_array));}

            //Capacity
            size_t 					size() const {return (this->v_size);}
            size_t                  capacity() const {return (this->v_capacity);}
			bool					empty() const {return ((this->v_size == 0) ? true : false);}
			size_t					max_size() const {return ((std::numeric_limits<size_t>::max() / sizeof(T)));}
            void                    reserve (size_t count);
            void                    resize (size_t count, T data = T());

            //Element access
            T &operator[](size_t count) {return (*(this->v_array + count));}
            T const &operator[](size_t count) const {return (*(this->v_array + count));}

            //Modifiers
            void clear();
            void push_back(const T &data);
			

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

template<class T>
vector<T>::vector(iterator first, iterator last)
{
    this->v_array = NULL;
    this->v_capacity = 0;
    this->v_size = 0;
    iterator temp_it = first;
    size_t temp_size = 0;
    while (temp_it != last)
    {
        ++temp_it;
        temp_size++;
    }
    this->reserve(temp_size);
    std::memcpy(static_cast<void *>(this->v_array), static_cast<void *>(first.getData()), sizeof(T) * temp_size);
    this->v_size = temp_size;
}

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
        T *temp = static_cast<T*>(operator new(sizeof(T) * count + 1));
        if (this->v_size > 0)
        {
            std::memcpy(static_cast<void *>(temp), static_cast<void *>(this->v_array), this->v_size * sizeof(T));
            delete [] this->v_array;
        }
        this->v_capacity = count;
        this->v_array = temp;
    }
}

template<class T>
void vector<T>::resize(size_t count, T data)
{
    if (count > this->v_size)
    {
        this->reserve(count);
        for (size_t i = this->v_size; i < count; i++)
            this->v_array[i] = data;
    }
    else
        this->reserve(this->v_size);
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

template<class T>
void vector<T>::push_back(const T &data)
{
    this->v_size++;
    std::stringstream ss;
    ss << this->v_size;
    size_t up = ss.str().size();
    T *temp = static_cast<T*>(operator new(sizeof(T) * this->v_size + up));
    if (this->v_size > 1)
    {
        std::memcpy(static_cast<void *>(temp), static_cast<void *>(this->v_array), (this->v_size - 1) * sizeof(T));
        delete [] this->v_array;
    }
    this->v_capacity = this->v_size + up;
    this->v_array = temp;
    this->v_array[this->v_size - 1] = data;
}

} //namespace